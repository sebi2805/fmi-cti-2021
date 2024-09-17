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