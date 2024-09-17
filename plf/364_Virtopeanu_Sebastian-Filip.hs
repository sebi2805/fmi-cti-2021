import Data.Char
import Data.Maybe
import Control.Monad
import Control.Applicative
import System.Random
import Data.List

-- Subiect Testare Haskell - 18 iunie 2024, ora 10, seria 36
-- Nume: Virtopeanu 
-- Prenume: Sebastian
-- Grupa: 364
-- Sala: Amf. Titeica
-- Rand amfiteatru: 2
-- Pozitie in banca: 4

-- Datele de mai sus nu sunt optionale! 
-- Sursele fara datele completate nu vor fi evaluate.

-- Atentie! Unele functii sunt comentate, deoarece nu sunt implementate toate instantele de clase / functiile ajutatoare necesare
-- pe masura ce implementati, puteti sa decomentati

-- util: veti folosi fromJust la un moment dat, este predefinta in Data.Maybe 
-- fromJust primeste un (Just ceva) si va returneaza acel ceva
-- fromJust :: Maybe a -> a 
-- fromJust (Just 2) = 2 dar fromJust Nothing -> arunca exceptie




import Data.Char
import Data.Maybe
import Control.Monad
import Control.Applicative
import Data.List

type Image = Char
type Column = Int
type Line = Int

data Position = Position
    { line :: Line,
      column :: Column
    }

data Elem = Elem
    { image :: Image,
      position :: Position
    }

type Playground = [Elem]

posExample :: Position
posExample = Position {line = 1, column = 1}

elemExample :: Elem
elemExample = Elem { image = 'A', position = Position {line = 1, column = 1} }

playground :: Playground
playground = [Elem { image = 'A', position = Position {line = 1, column = 1}},
              Elem { image = 'C', position = Position {line = 1, column = 2}},
              Elem { image = 'B', position = Position {line = 2, column = 1}},
              Elem { image = 'C', position = Position {line = 2, column = 2}},
              Elem { image = 'B', position = Position {line = 2, column = 3}},
              Elem { image = 'A', position = Position {line = 3, column = 1}}]

-- la final am adaugat codul copiat din proiectul meu de cabal in caz ca am omis ceva

-- instance Eq Position where 
instance Eq Position where
 (Position l1 c1) == (Position l2 c2) = l1 == l2 && c1 == c2
-- instance Show Position where 
instance Show Position where
          show (Position l c) = "["++show l ++ "," ++ show c ++ "]"
-- instance Eq Elem where 
instance Eq Elem where
          (Elem img1 pos1) == (Elem img2 pos2) = img1 == img2 && pos1==pos2
-- instance Show Elem where 
instance Show Elem where
          show (Elem img pos) = show pos ++ " with " ++ show img

-- vad ca in cerinta folosesti getElemsByPositionFoldr, dar in fisier era getElemByPositionFoldr
getElemsByPositionFoldr :: Position -> Playground -> Maybe Elem
getElemsByPositionFoldr search = foldr (\x acc -> if position x == search then Just x else acc)  Nothing
-- sau asa in care folosesc si elems 
-- getElemByPositionFoldr search elems = foldr (\x acc -> if position x == search then Just x else acc)  Nothing elems
--  afisarea nu e exact ca in pdf, TODO inaite 

getElemByPosition :: Position -> Playground -> Maybe Elem
getElemByPosition pos elems = let list = filter (\e -> position e == pos) elems
                              in if null list then Nothing
                              else Just (head list)

-- varianta cu list comprehension
-- getElemByPosition :: Position -> Playground -> Maybe Elem
-- getElemByPosition pos elems = let list = [elem | elem <- elems, pos == position elem]
--                                         in if null list then Nothing
--                                         else Just (head list)

--  nu am mai apucat sa testez sa nu mergea arbitrary
instance Arbitrary Position where 
    arbitrary = do 
          line <- arbitrary
          col <- arbitrary 
          return (Position line col)

instance Arbitrary Elem where 
    arbitrary = do 
          image <- arbitrary
          position <- arbitrary 
          return (Elem image position)

prop_for_qc :: Position -> Playground -> Bool 
prop_for_qc pos elems = (getElemByPosition pos elems) ==  (getElemsByPositionFoldr pos elems)

test_position_qc = quickCheck prop_for_qc

type Move = (Position, Position)


checkElems :: (Maybe Elem, Maybe Elem) -> Bool
checkElems (Nothing, _)  = False
checkElems (_, Nothing)  = False
checkElems (Just m1, Just m2) = image m1 == image m2

eliminateElems :: (Maybe Elem, Maybe Elem) -> Playground -> Playground
eliminateElems (Just e1, Just e2) = filter (\e -> e1 /= e && e2 /= e)

playRound :: Move -> Playground -> (Playground, Maybe Elem, Maybe Elem)
playRound (m1, m2) elems = let elem1 = getElemsByPositionFoldr m1 elems
                               elem2 = getElemsByPositionFoldr m2 elems
                           in if checkElems (elem1, elem2) then
                                        (eliminateElems (elem1, elem2) elems, elem1, elem2)
                              else (elems, Nothing, Nothing)



type GameLog = [String]
data GameWriter a = GameWriter { runGameWriter :: (a, GameLog) }
    deriving Show

-- instance Functor GameWriter where 
instance Functor GameWriter where
          fmap f (GameWriter (a, log)) = GameWriter (f a, log)
-- instance Applicative GameWriter where 
instance Applicative GameWriter where
  pure a = GameWriter (a, [])
  (GameWriter (f, log1)) <*> (GameWriter (a, log2)) = GameWriter (f a, log1++log2)

-- instance Monad GameWriter where 
instance Monad GameWriter where
          (GameWriter (a, log1)) >>= f = let GameWriter (b, log2) = f a
                                        in GameWriter (b, log1++log2)

strImage :: Maybe Elem -> String
strImage elem = show $ image $ fromJust elem

strLine :: Maybe Elem -> String
strLine elem = show $ line $ position $ fromJust elem

strColumn :: Maybe Elem -> String
strColumn elem = show $ column $ position $ fromJust elem

playRoundMonad :: Move -> Playground -> GameWriter Playground
playRoundMonad m elems = let (newElems, e1, e2) = playRound m elems
                         in if null newElems then
                              GameWriter (newElems, ["You won!"])
                              else if isNothing e1 || isNothing e2 then
                              GameWriter (elems, ["Bad move try again"])
                              else GameWriter (newElems, ["Good move!" ++ show(image (fromJust e1)) ++ " was removed from positions " ++ show(position (fromJust e1)) ++ " and position " ++show(position (fromJust e2))])

firstMove :: Move
firstMove = (Position {line = 1, column = 1}, Position {line = 3, column = 1})

secondMove :: Move
secondMove = (Position {line = 1, column = 2}, Position {line = 2, column = 1})

thirdMove :: Move
thirdMove = (Position {line = 1, column = 2}, Position {line = 2, column = 2})

fourthMove :: Move
fourthMove = (Position {line = 2, column = 1}, Position {line = 2, column = 3})

runGame :: Playground -> GameWriter Playground
runGame playground = do 
    move1 <- playRoundMonad firstMove playground 
    move2 <- playRoundMonad secondMove move1 
    move3 <- playRoundMonad thirdMove move2 
    move4 <- playRoundMonad fourthMove move3 
    return move4

mainGame :: IO ()
mainGame = do 
    let playground = [Elem { image = 'A', position = Position {line = 1, column = 1}}, 
                      Elem { image = 'C', position = Position {line = 1, column = 2}},
                      Elem { image = 'B', position = Position {line = 2, column = 1}},
                      Elem { image = 'C', position = Position {line = 2, column = 2}},
                      Elem { image = 'B', position = Position {line = 2, column = 3}},
                      Elem { image = 'A', position = Position {line = 3, column = 1}}] 
    let (newPlayground, log) = runGameWriter (runGame playground)
    mapM_ putStrLn log 
-----------------------------------------------------------------------------------------------------------------------
------------------FINAL TESTARE----------------------------------------------------------------------------------------
--------------------------------FINAL TESTARE--------------------------------------------------------------------------
----------------------------------------------FINAL TESTARE------------------------------------------------------------
-- NU SCHIMBATI NIMIC MAI JOS 
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

 ------Module QuickCheck-----------------------------------
 --- sursa: https://www.cse.chalmers.se/~rjmh/QuickCheck/QuickCheck.hs

infixr 0 ==>
infix  1 `classify`

--------------------------------------------------------------------
-- Generator

newtype Gen a
  = Gen (Int -> StdGen -> a)

sized :: (Int -> Gen a) -> Gen a
sized fgen = Gen (\n r -> let Gen m = fgen n in m n r)

resize :: Int -> Gen a -> Gen a
resize n (Gen m) = Gen (\_ r -> m n r)

rand :: Gen StdGen
rand = Gen (\n r -> r)

promote :: (a -> Gen b) -> Gen (a -> b)
promote f = Gen (\n r -> \a -> let Gen m = f a in m n r)

variant :: Int -> Gen a -> Gen a
variant v (Gen m) = Gen (\n r -> m n (rands r !! (v+1)))
 where
  rands r0 = r1 : rands r2 where (r1, r2) = split r0

generate :: Int -> StdGen -> Gen a -> a
generate n rnd (Gen m) = m size rnd'
 where
  (size, rnd') = randomR (0, n) rnd

--instance Functor Gen where
--  fmap f m = m >>= return . f

instance Monad Gen where
  Gen m >>= k =
    Gen (\n r0 -> let (r1,r2) = split r0
                      Gen m'  = k (m n r1)
                   in m' n r2)
                   
instance Applicative Gen where
  pure a = Gen (\n r -> a)
  mf <*> ma = do
    f <- mf
    a <- ma
    return (f a)       

instance Functor Gen where              
  fmap f ma = pure f <*> ma                     

-- derived

choose :: Random a => (a, a) -> Gen a
choose bounds = (fst . randomR bounds) `fmap` rand

elements :: [a] -> Gen a
elements xs = (xs !!) `fmap` choose (0, length xs - 1)

vector :: Arbitrary a => Int -> Gen [a]
vector n = sequence [ arbitrary | i <- [1..n] ]

oneof :: [Gen a] -> Gen a
oneof gens = elements gens >>= id

frequency :: [(Int, Gen a)] -> Gen a
frequency xs = choose (1, tot) >>= (`pick` xs)
 where
  tot = sum (map fst xs)

  pick n ((k,x):xs)
    | n <= k    = x
    | otherwise = pick (n-k) xs

-- general monadic

two :: Monad m => m a -> m (a, a)
two m = liftM2 (,) m m

three :: Monad m => m a -> m (a, a, a)
three m = liftM3 (,,) m m m

four :: Monad m => m a -> m (a, a, a, a)
four m = liftM4 (,,,) m m m m

--------------------------------------------------------------------
-- Arbitrary

class Arbitrary a where
  arbitrary   :: Gen a
  --coarbitrary :: a -> Gen b -> Gen b

instance Arbitrary () where
  arbitrary     = return ()
 -- coarbitrary _ = variant 0

instance Arbitrary Bool where
  arbitrary     = elements [True, False]
  --coarbitrary b = if b then variant 0 else variant 1

instance Arbitrary Char where
  arbitrary     = choose (32,255) >>= \n -> return (chr n)
 -- coarbitrary n = variant (ord n)

instance Arbitrary Int where
  arbitrary     = sized $ \n -> choose (-n,n)
 -- coarbitrary n = variant (if n >= 0 then 2*n else 2*(-n) + 1)


instance Arbitrary Integer where
  arbitrary     = sized $ \n -> choose (-fromIntegral n,fromIntegral n)
  --coarbitrary n = variant $ (fromInteger(if n >= 0 then 2*n else 2*(-n) + 1)) 

instance Arbitrary Float where
  arbitrary     = liftM3 fraction arbitrary arbitrary arbitrary 
  --coarbitrary x = coarbitrary (decodeFloat x)

instance Arbitrary Double where
  arbitrary     = liftM3 fraction arbitrary arbitrary arbitrary 
 -- coarbitrary x = coarbitrary (decodeFloat x)

fraction a b c = fromInteger a + (fromInteger b / (abs (fromInteger c) + 1))

{-
instance Arbitrary Integer where
  arbitrary     = sized $ \n -> choose (-fromInt n,fromInt n)
  coarbitrary n = variant (fromInteger (if n >= 0 then 2*n else 2*(-n) + 1))

instance Arbitrary Float where
  arbitrary     = liftM3 fraction arbitrary arbitrary arbitrary 
  coarbitrary x = coarbitrary (decodeFloat x)

instance Arbitrary Double where
  arbitrary     = liftM3 fraction arbitrary arbitrary arbitrary 
  coarbitrary x = coarbitrary (decodeFloat x)

fraction a b c = fromInteger a + (fromInteger b / (abs (fromInteger c) + 1))
-}


instance (Arbitrary a, Arbitrary b) => Arbitrary (a, b) where
  arbitrary          = liftM2 (,) arbitrary arbitrary
 -- coarbitrary (a, b) = coarbitrary a . coarbitrary b

instance (Arbitrary a, Arbitrary b, Arbitrary c) => Arbitrary (a, b, c) where
  arbitrary             = liftM3 (,,) arbitrary arbitrary arbitrary
  --coarbitrary (a, b, c) = coarbitrary a . coarbitrary b . coarbitrary c

instance (Arbitrary a, Arbitrary b, Arbitrary c, Arbitrary d)
      => Arbitrary (a, b, c, d)
 where
  arbitrary = liftM4 (,,,) arbitrary arbitrary arbitrary arbitrary
  --coarbitrary (a, b, c, d) =
  --  coarbitrary a . coarbitrary b . coarbitrary c . coarbitrary d

instance Arbitrary a => Arbitrary [a] where
  arbitrary          = sized (\n -> choose (0,n) >>= vector)
 -- coarbitrary []     = variant 0
 -- coarbitrary (a:as) = coarbitrary a . variant 1 . coarbitrary as

--instance (Arbitrary a, Arbitrary b) => Arbitrary (a -> b) where
 -- arbitrary         = promote (`coarbitrary` arbitrary)
 -- coarbitrary f gen = arbitrary >>= ((`coarbitrary` gen) . f)

--------------------------------------------------------------------
-- Testable

data Result
  = Result { ok :: Maybe Bool, stamp :: [String], arguments :: [String] }

nothing :: Result
nothing = Result{ ok = Nothing, stamp = [], arguments = [] }

newtype Property
  = Prop (Gen Result)

result :: Result -> Property
result res = Prop (return res)

evaluate :: Testable a => a -> Gen Result
evaluate a = gen where Prop gen = property a

class Testable a where
  property :: a -> Property

instance Testable () where
  property _ = result nothing

instance Testable Bool where
  property b = result (nothing{ ok = Just b })

instance Testable Result where
  property res = result res

instance Testable Property where
  property prop = prop

instance (Arbitrary a, Show a, Testable b) => Testable (a -> b) where
  property f = forAll arbitrary f

forAll :: (Show a, Testable b) => Gen a -> (a -> b) -> Property
forAll gen body = Prop $
  do a   <- gen
     res <- evaluate (body a)
     return (argument a res)
 where
  argument a res = res{ arguments = show a : arguments res }

(==>) :: Testable a => Bool -> a -> Property
True  ==> a = property a
False ==> a = property ()

label :: Testable a => String -> a -> Property
label s a = Prop (add `fmap` evaluate a)
 where
  add res = res{ stamp = s : stamp res }

classify :: Testable a => Bool -> String -> a -> Property
classify True  name = label name
classify False _    = property

trivial :: Testable a => Bool -> a -> Property
trivial = (`classify` "trivial")

collect :: (Show a, Testable b) => a -> b -> Property
collect v = label (show v)

--------------------------------------------------------------------
-- Testing

data Config = Config
  { maxTest :: Int
  , maxFail :: Int
  , size    :: Int -> Int
  , every   :: Int -> [String] -> String
  }

quick :: Config
quick = Config
  { maxTest = 100
  , maxFail = 1000
  , size    = (+ 3) . (`div` 2)
  , every   = \n args -> let s = show n in s ++ [ '\b' | _ <- s ]
  }
         
verbose :: Config
verbose = quick
  { every = \n args -> show n ++ ":\n" ++ unlines args
  }

test, quickCheck, verboseCheck :: Testable a => a -> IO ()
test         = check quick
quickCheck   = check quick
verboseCheck = check verbose
         
check :: Testable a => Config -> a -> IO ()
check config a =
  do rnd <- newStdGen
     tests config (evaluate a) rnd 0 0 []

tests :: Config -> Gen Result -> StdGen -> Int -> Int -> [[String]] -> IO () 
tests config gen rnd0 ntest nfail stamps
  | ntest == maxTest config = do done "OK, passed" ntest stamps
  | nfail == maxFail config = do done "Arguments exhausted after" ntest stamps
  | otherwise               =
      do putStr (every config ntest (arguments result))
         case ok result of
           Nothing    ->
             tests config gen rnd1 ntest (nfail+1) stamps
           Just True  ->
             tests config gen rnd1 (ntest+1) nfail (stamp result:stamps)
           Just False ->
             putStr ( "Falsifiable, after "
                   ++ show ntest
                   ++ " tests:\n"
                   ++ unlines (arguments result)
                    )
     where
      result      = generate (size config ntest) rnd2 gen
      (rnd1,rnd2) = split rnd0

done :: String -> Int -> [[String]] -> IO ()
done mesg ntest stamps =
  do putStr ( mesg ++ " " ++ show ntest ++ " tests" ++ table )
 where
  table = display
        . map entry
        . reverse
        . sort
        . map pairLength
        . group
        . sort
        . filter (not . null)
        $ stamps

  display []  = ".\n"
  display [x] = " (" ++ x ++ ").\n"
  display xs  = ".\n" ++ unlines (map (++ ".") xs)

  pairLength xss@(xs:_) = (length xss, xs)
  entry (n, xs)         = percentage n ntest
                       ++ " "
                       ++ concat (intersperse ", " xs)

  percentage n m        = show ((100 * n) `div` m) ++ "%"

--------------------------------------------------------------------
-- the end.

-- import Data.Char
-- import Data.Maybe
-- import Control.Monad
-- import Control.Applicative
-- import Data.List

-- type Image = Char
-- type Column = Int
-- type Line = Int

-- data Position = Position
--     { line :: Line,
--       column :: Column
--     }

-- data Elem = Elem
--     { image :: Image,
--       position :: Position
--     }

-- type Playground = [Elem]

-- posExample :: Position
-- posExample = Position {line = 1, column = 1}

-- elemExample :: Elem
-- elemExample = Elem { image = 'A', position = Position {line = 1, column = 1} }

-- playground :: Playground
-- playground = [Elem { image = 'A', position = Position {line = 1, column = 1}},
--               Elem { image = 'C', position = Position {line = 1, column = 2}},
--               Elem { image = 'B', position = Position {line = 2, column = 1}},
--               Elem { image = 'C', position = Position {line = 2, column = 2}},
--               Elem { image = 'B', position = Position {line = 2, column = 3}},
--               Elem { image = 'A', position = Position {line = 3, column = 1}}]

-- -- instance Eq Position where 
-- instance Eq Position where
--  (Position l1 c1) == (Position l2 c2) = l1 == l2 && c1 == c2
-- -- instance Show Position where 
-- instance Show Position where
--           show (Position l c) = "["++show l ++ "," ++ show c ++ "]"
-- -- instance Eq Elem where 
-- instance Eq Elem where
--           (Elem img1 pos1) == (Elem img2 pos2) = img1 == img2 && pos1==pos2
-- -- instance Show Elem where 
-- instance Show Elem where
--           show (Elem img pos) = show pos ++ " with " ++ show img

-- -- vad ca in cerinta folosesti getElemsByPositionFoldr, dar in fisier era getElemByPositionFoldr
-- getElemsByPositionFoldr :: Position -> Playground -> Maybe Elem
-- getElemsByPositionFoldr search = foldr (\x acc -> if position x == search then Just x else acc)  Nothing
-- -- sau asa in care folosesc si elems 
-- -- getElemByPositionFoldr search elems = foldr (\x acc -> if position x == search then Just x else acc)  Nothing elems
-- --  afisarea nu e exact ca in pdf, TODO inaite 

-- getElemByPosition :: Position -> Playground -> Maybe Elem
-- getElemByPosition pos elems = let list = filter (\e -> position e == pos) elems
--                               in if null list then Nothing
--                               else Just (head list)

-- -- varianta cu list comprehension
-- -- getElemByPosition :: Position -> Playground -> Maybe Elem
-- -- getElemByPosition pos elems = let list = [elem | elem <- elems, pos == position elem]
-- --                                         in if null list then Nothing
-- --                                         else Just (head list)

-- --  nu am mai apucat sa testez sa nu mergea arbitrary
-- -- instance Arbitrary Position where 
-- --     arbitrary = do 
-- --           line <- arbitrary
-- --           col <- arbitrary 
-- --           return (Position line col)

-- -- instance Arbitrary Elem where 
-- --     arbitrary = do 
--           -- image <- arbitrary
--           -- position <- arbitrary 
--           -- return (Elem image position)

-- -- prop_for_qc :: Position -> Playground -> Bool 
-- -- prop_for_qc pos elems = (getElemByPosition pos elems) ==  (getElemsByPositionFoldr pos elems)

-- -- test_position_qc = quickCheck prop_for_qc

-- type Move = (Position, Position)


-- checkElems :: (Maybe Elem, Maybe Elem) -> Bool
-- checkElems (Nothing, _)  = False
-- checkElems (_, Nothing)  = False
-- checkElems (Just m1, Just m2) = image m1 == image m2

-- eliminateElems :: (Maybe Elem, Maybe Elem) -> Playground -> Playground
-- eliminateElems (Just e1, Just e2) = filter (\e -> e1 /= e && e2 /= e)

-- playRound :: Move -> Playground -> (Playground, Maybe Elem, Maybe Elem)
-- playRound (m1, m2) elems = let elem1 = getElemsByPositionFoldr m1 elems
--                                elem2 = getElemsByPositionFoldr m2 elems
--                            in if checkElems (elem1, elem2) then
--                                         (eliminateElems (elem1, elem2) elems, elem1, elem2)
--                               else (elems, Nothing, Nothing)



-- type GameLog = [String]
-- data GameWriter a = GameWriter { runGameWriter :: (a, GameLog) }
--     deriving Show

-- -- instance Functor GameWriter where 
-- instance Functor GameWriter where
--           fmap f (GameWriter (a, log)) = GameWriter (f a, log)
-- -- instance Applicative GameWriter where 
-- instance Applicative GameWriter where
--   pure a = GameWriter (a, [])
--   (GameWriter (f, log1)) <*> (GameWriter (a, log2)) = GameWriter (f a, log1++log2)

-- -- instance Monad GameWriter where 
-- instance Monad GameWriter where
--           (GameWriter (a, log1)) >>= f = let GameWriter (b, log2) = f a
--                                         in GameWriter (b, log1++log2)

-- strImage :: Maybe Elem -> String
-- strImage elem = show $ image $ fromJust elem

-- strLine :: Maybe Elem -> String
-- strLine elem = show $ line $ position $ fromJust elem

-- strColumn :: Maybe Elem -> String
-- strColumn elem = show $ column $ position $ fromJust elem

-- playRoundMonad :: Move -> Playground -> GameWriter Playground
-- playRoundMonad m elems = let (newElems, e1, e2) = playRound m elems
--                          in if null newElems then
--                               GameWriter (newElems, ["You won!"])
--                               else if isNothing e1 || isNothing e2 then
--                               GameWriter (elems, ["Bad move try again"])
--                               else GameWriter (newElems, ["Good move!" ++ show(image (fromJust e1)) ++ " was removed from positions " ++ show(position (fromJust e1)) ++ " and position " ++show(position (fromJust e2))])

-- firstMove :: Move
-- firstMove = (Position {line = 1, column = 1}, Position {line = 3, column = 1})

-- secondMove :: Move
-- secondMove = (Position {line = 1, column = 2}, Position {line = 2, column = 1})

-- thirdMove :: Move
-- thirdMove = (Position {line = 1, column = 2}, Position {line = 2, column = 2})

-- fourthMove :: Move
-- fourthMove = (Position {line = 2, column = 1}, Position {line = 2, column = 3})

-- runGame :: Playground -> GameWriter Playground
-- runGame playground = do 
--     move1 <- playRoundMonad firstMove playground 
--     move2 <- playRoundMonad secondMove move1 
--     move3 <- playRoundMonad thirdMove move2 
--     move4 <- playRoundMonad fourthMove move3 
--     return move4

-- mainGame :: IO ()
-- mainGame = do 
--     let playground = [Elem { image = 'A', position = Position {line = 1, column = 1}}, 
--                       Elem { image = 'C', position = Position {line = 1, column = 2}},
--                       Elem { image = 'B', position = Position {line = 2, column = 1}},
--                       Elem { image = 'C', position = Position {line = 2, column = 2}},
--                       Elem { image = 'B', position = Position {line = 2, column = 3}},
--                       Elem { image = 'A', position = Position {line = 3, column = 1}}] 
--     let (newPlayground, log) = runGameWriter (runGame playground)
--     mapM_ putStrLn log 