typedef struct {
	
	stack<int> content;
	stack<int> minElts;
	stack<int> maxElts;
	
} minMaxStack;


bool empty(minMaxStack *s){
	return (s->content).empty();
}

void push(minMaxStack *s, int e){
	(s->content).push(e);
	if( ( (s->minElts).empty() ) || (e <= (s->minElts).top()))
	 (s->minElts).push(e);
	if( ( (s->maxElts).empty() ) || (e >= (s->maxElts).top()))
	 (s->maxElts).push(e);
}

int pop(minMaxStack *s){
	int e = (s->content).pop();
	if( e == (s->minElts).top() )
	 (s->minElts).pop();
	if( e == (s->maxElts).top() )
	 (s->maxElts).pop();
	return e;
}

int min(minMaxStack *s){
	return (s->minElts).top();
}

int max(minMaxStack *s){
	return (s->maxElts).top();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//in-place heap sort

typedef struct{
	vector<int> *content;
	int c = 0;
} max_heap;

bool empty(max_heap *h){
  return (h->c == 0);
}

int max(max_heap *h){
  return h->content->at(0);	
}

//routines
void swap(vector<int> *v, int i, int j){
	int tmp = v->at(i);
	v->at(i) = v->at(j);
	v->at(j) = tmp;
}
int tata(int i){
	return (i+1)/2 - 1;
}
int fiuStinga(int i){
	return 2*(i+1) - 1;
}
int fiuDreapta(int i){
	return 2(i+1);
}

//basic operations
void removeMax(max_heap *h){
	swap(h->content,0,h->c--);
	int i = 0;
	while( (fiuStinga(i) < h->c) /*elementul are copii*/ 
	         &&  ( ( h->content->at(i) > h->content->at(fiuStinga(i))  )
			        ||  (   (fiuDreapta(i) < h-> c) && ( h->content->at(i) > h->content->at(fiuDreapta(i))  )
	))){
		int j = ( (fiuDreapta(i) >= c) || ( h->content->at(fiuStinga(i)) <= h->content->at(fiuDreapta(i)) ) ) ? fiuStinga(i) : fiuDreapta(i);
		swap(h->content,i,j);
		i = j;
	}
}
void add(max_heap *h, int p){
	h->content->at(h->c) = p;
	int i = h->c++;
	while( (i > 0)  &&  ( h->content->at(i) < h->content->at(tata(i)) )  ){
		swap(h->content,i,tata(i));
		i = tata(i);
	}
}

void heapSort(vector<int>& a){
	max_heap h; h.content = &a;
	for(int i = 0; i < a.size(); i++)
	 add(&h,a[i]);
	for(int i = a.size()-1; i >= 0; i--)
	 removeMax(&h);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//binary search

int binarySearch(const vector<int>& a, int e, int lb, int ub){
	if(ub < lb)
	 return -1;
	else{
	  int m = (lb+ub)/2;
	  if(a[m] == e)
	   return m;
	  else if(a[m] > e)
	   return binarySearch(a,e,lb,m-1);
	  else
	   return binarySearch(a,e,m+1,ub); 
	}
}

int binarySearch(const vector<int>& a, int e){
	return binarySearch(a,e,0,a.size()-1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//exponential search

int expSearch(const vector<int>& a, int e){
	int res = 0;
	while(res < a.size() && a[res] < e)
	 res *= 2;
	int lb = res/2, ub = res;
	if(ub >= a.size())
	 ub = a.size()-1;
	return binarySearch(a,e,lb,ub);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//peak
//assumption: all elements are pairwise different

int peak(const vector<int>& a, int lb, int ub){
	if( ub == lb )
	 return lb;
	else{
		int m = (lb+ub)/2;
		if(a[m] < a[m+1])
		 return peak(a,m+1,ub);
		else
		 return peak(a,lb,m);
	}
}

int peak(const vector<int>& a){
	return peak(a,0,a.size()-1);
}


///////////////////////////////////////////////////////////////////////////////////////////////////
//vector k-aproape sortat

void swap(vector<int>& a, int i, int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

bool aproape_sortat(vector<int> a, int k){
	vector<int> miscare(a.size());
	bool sortat;
	do{
		
		sortat = true;
		for(int i = 0; i < a.size() -1; i++)
		 if(a[i] > a[i+1]){
		 	swap(a,i,i+1);
			swap(miscare,i,i+1);
			miscare[i]++; miscare[i+1]++;
			if(miscare[i] > k || miscare[i+1] > k)
			 return false;
		 }
		
	}while(!sortat);
	return true;
}


//assumption: vector is k-almost sorted
int search(const vector<int>& a, int e, int k, int lb, int ub){
	if(ub < lb)
	 return -1;
	else{
		int m = (lb+ub)/2;
		if(a[m] == e)
		 return m;
		else if(a[m] < e){
			for(int i = m-1; i >= lb && i >= m-k; i--)
			 if(a[i] == e)
			  return i;
			 return search(a,e,k,m+1,ub);
		}else{ //a[m] > e
			for(int i = m+1; i <= ub && i <= m+k; i++)
			 if(a[i] == e)
			  return i;
			 return search(a,e,k,lb,m-1);
		}
	}
}

int search(const vector<int>& a, int e, int k){
	return search(a,e,k,0,a.size()-1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//vector circular sortat

int min(const vector<int>& a, int lb, int ub){
	if(lb == ub)
	 return lb;
	else{
		int m = (lb+ub)/2;
		if(a[m] > a[ub])
		 return min(a,m+1,ub);
		else
		 return min(a,lb,m);
	}
}

int min(const vector<int>& a){
	return min(a,0,a.size()-1);
}

int circular_search(const vector<int>& a){
	int m = min(a);
	int i = binarySearch(a,0,i-1);
	return (i == -1) ? binarySearch(a,i,a.size()-1) : i;
}