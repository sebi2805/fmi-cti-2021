//compute maximum product of three numbers of a given array of integers
int get3Max(vector<int>& a){
	int i,j,k;
	vector<int> tmp;
	
	//3 smallest elements
	for(k = 0; k < 3; k++){
	 for(i = k+1; i < a.size(); i++)
	  if(a[i] < a[k])
	   swap(a,i,k);
	  tmp.push_back(a[k]);
	 }
	 
	 //3 largest elements  
	 for(k=1; k <= 3; k++){
	  for(i = 2+k; i < a.size() - k; i++)
	   if(a[i] > a[a.size()-k])
	    swap(a,i,a.size()-k);
	  tmp.push_back(a[a.size()-k]);
	 }	
		
	 int res = tmp[0]*tmp[1]*tmp[2];
	 for(i = 0; i < 6; i++)
	  for(j = i+1; j < 6; j++)
	   for(k = j+1; k < 6; k++)
	    if(res < tmp[i]*tmp[j]*tmp[k])
		 res = tmp[i]*tmp[j]*tmp[k];
		 
	 return res; 
}

//find the top k integers that occur the most frequently in an array

vector<int> topK(vector<int> a, int k){
	sort(a.begin(),a.end());
	list< pair<int,int> > l;
	int i = 0;
	while(i < a.size()){
		pair<int,int> e;
		e.first = 0;
		e.second = a[i];
		while(a[i] == e.second){ e.first++; i++; }
		l.push_back(e);
	}
	l.sort();
	vector<int> res(k);
	for(i = 0; i < k; i++){ res[i] = l.back().second; l.pop_back(); }
	return res; 
}

//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix

typedef vector< vector<int> > matrix;

typedef struct {
	int e,i,j;
} cell;

typedef priority_queue<cell> heap;

int statistics(const matrix& m, int k){
	int n = m.size();
	heap h;
	h.push(cell(m[0][0],0,0));
	for(int i = 0; i < k; i++){
		int s = h.top(); h.pop();
		if(s.i < n-1)
		 h.push(cell(m[s.i+1][s.j],s.i+1,s.j));
		if(s.j < n-1)
		 h.push(cell(m[s.i][s.j+1],s.i,s.j+1));
	}
	return h.top().e;
}

//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. Propose an algorithm in order to compute the nth ugly number.
int ugly(int n){
	heap_binar h; init_hb(&h,3*n+1);
	add(&h,1);
	for(int i = 0; i < n; i++){
		int m = min(&h);
		removeMin(&h);
		add(&h,5*m);
		if(m % 5){
			add(&h,3*m);
			if(m % 3)
			 add(&h,2*m);
		}
	}
	return min(&h);
}

//Discussion: dynamic binary heap. How to implement it efficiently?
//solution: modify insertion of elements
void add(heap *h, int p){
	//part added
	if( h->c == (h->content).size() )
	 (h->content).resize(2*h->c); //explanation: when we double the size of the vector, the number of elements doubled since the latest resize. 
	//Amortized complexity: O(1)
	//usual code
	(h->content)[h->c] = p;
	int i = h->c++;
	while( (i > 0)  &&  ( (h->content)[i] < (h->content)[tata(i)] )  ){
		swap(&(h->content),i,tata(i));
		i = tata(i);
	}
}