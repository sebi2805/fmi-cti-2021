/////////////////////////////////////////////////////////////////////////
//anagrame

bool anagrame(string x, string y) {
	
	vector<int> apariti(256);
	
	for(int i =0; i < x.size(); i++){
		apariti[x.at(i)]++;
	}
	for(int j =0; j < y.size(); j++){
		apariti[y.at(j)]--;
	}
	for(int k = 0; k < apariti.size(); k++)
		if(apariti[k])
		 return 0;
		 
	return 1;
	
}

/////////////////////////////////////////////////////////////////////////
//numarul de pereche distincte i,j a.i. a[i]+a[j] = S
//ipoteza: a este sortat

int nrPereche(vector<int>& a, int S){
	
	int i = 0, 
	    j = a.length() - 1, 
		res = 0;
		
	while(i < j){
		
		if(a[i] + a[j] < S)
			i++;
		else if(a[i] + a[j] > S)
			j--;
		else{
		  if(a[i] == a[j]){ //= S/2
		    res += (j-i+1)*(j-i)/2;
			break;
		  }else{
		  	int ni = 1;
			while(a[i] == a[i+1]){ ni++; i++; }
			int nj=1;
			while(a[j-1] == a[j]){ nj++; j--; }
			res += ni*nj;
			i++; j--;
		  }	
		}
		
	}
	
	return res;
	
}

/////////////////////////////////////////////////////////////////////////
//assumption: if we remove the k least elements from the vector, then it is sorted


//Solution 1: O(kn)

void sortare1(vector<int>& a, int k){
	
	
	vector<int> b(a), c;
	
	int i,j,m;
	for(int i = 0; i < k; i++){
		m =0;
		for(j = 1; j < b.size(); j++)
		 if(b[j] > b[m])
		  m = j;
		a[i] = b[m];
		c = vector<int>(b.size()-1);
		for(j = 0; j < m; j++)
		 c[j] = b[j];
		for(j = m+1; j < b.size(); j++)
		 c[j-1] = b[j];
		b = c;
	} 
	
	for(i = k; i < a.size(); i++)
	 a[i] = b[i-k];
	
}

//Solution 2: O(nlog(k))

void sortare2(vector<int>& a, int k){
	
	priority_queue< pair<int,int> > tmp; //store k smallest elements
	
	int i,j;
	
	for(i = 0; i < a.size(); i++){
	  if(tmp.size() < k)
	   tmp.push(pair<int,int>(-a[i],i)); //multiply by -1 to have a max heap
	  else if( tmp.top() < -a[i] ){
	  	tmp.pop();
		tmp.push(pair<int,int>(-a[i],i));
	  }	
	}
	
	priority_queue<int> h1, h2;
	while(!tmp.empty()){
		pair<int,int> p = tmp.top();
		h1.push(-p.first);
		h2.push(p.second);
		tmp.pop();
	}
	
	vector<int> b(a.size()-k);
	for(i = 0, j = 0; i < b.size(); j++){
		if( h2.empty()  ||  ( j != h2.top() ) )
		 b[i++] = a[j];
		else
		 h2.pop();
	}
	
	for(i = 0; i < a.size(); i++)
	 if(i < k){
	 	a[i] = h1.top();
		h1.pop();
	 }else
	  a[i] = b[i-k];
	  
}


//Solution 3: O(n+klogn)


void sortare3(vector<int>& a, int k){
	
	priority_queue< pair<int,int> > h;
	
	for(int i =0; i < a.size(); i++){
		h.push(pair<int,int>(a[i],i)); //n inserti de facut: O(nlogn) daca este heap binar! =(  dar O(n) daca este heap Fibonacci
	}
	
	priority_queue<int> h1, h2;
	for(int i = 0; i <k ; i++){
		h1.push(h.top().first);
		h2.push(h.top().second);
		h.pop(); //k stergeri: O(klog(n))
	}
	
	vector<int> b(a);
	
	for(int i = 0; i < k; i++){
		a[i] = h1.top();
		h1.pop();
	}
	
	for(int i = 0, j = k; i < a.size(); i++){
	  if( h2.empty() ||  i != h2.top() )
	   a[j++] = b[i];
	  else h2.pop(); 
	}
	
}

//Solution 4: O(n + klogk)
//ipoteza: all elements are different

int cautare_statistica(vector<int>& a, int k); //cf. seminarul 4

void sortare4(vector<int>& a, int k){
	
	priority_queue< pair<int,int> > h;
	
	int m = cautare_statistica(a,k-1); //kth smallest element
	
	for(int i = 0; i < a.size(); i++)
	 if(a[i] <= m)
	  h.push(pair<int,int>(a[i],i));
	  
	priority_queue<int> h1, h2;
	while(!h.empty()){
		h1.push(h.top().first);
		h2.push(h.top().second);
		h.pop();
	}
	
	vector<int> b(a);
	
	for(int i = 0; i < k; i++){
		a[i] = h1.top();
		h1.pop();
	}
	
	for(int i = 0, j = k; i < a.size(); i++){
	  if( h2.empty() ||  i != h2.top() )
	   a[j++] = b[i];
	  else h2.pop(); 
	}
	
}


































