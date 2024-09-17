/////////////////////////////////////////////////////////////////////////////////
//numar de inversiuni in un vector neordonat

int nrInversiuniAux(vector<int>& a, int lb, int ub){
	if(ub - lb < 1)
	 return 0;
	//ub - lb >= 1
	int m = (lb+ub)/2;
	int res = nrInversiuniAux(a,lb,m) 
		+ nrInversiuniAux(a,m+1,ub);
	//vector sortat intre lb si m, respectiv intre m+1 si ub
	vector<int> tmp(ub-lb+1);
	int i = lb, j = m+1, k = 0;
	while(i <= m && j <= ub){
		if(a[i]<=a[j]){
		 //in tmp sunt deja i-1 elemente de stinga
		 //sunt si k - i + 1 elemente de dreapta
		 res += k-i+1;
		 tmp[k++] = a[i++];
		}else{
		 tmp[k++] = a[j++];
		}
	}
	while(i <= m){ res+= ub-m; tmp[k++] = a[i++]; }
	while(j <= ub){ tmp[k++] = a[j++];}
	for(int k = lb; k <= ub; k++)
	 a[k] = tmp[k-lb];
	return res;
}

int nrInversiuni(vector<int>& a){
	return nrInversiuniAux(a,0,a.length - 1);
}

/////////////////////////////////////////////////////////////////////////////////
//acoperire minima

typedef struct interval {
	int a,b;
} interval;

bool compareInterval(interval i1, interval i2){
	return i1.a < i2.a;
}

int acoperire(interval i, vector<interval>& v){
	
	sort(v.begin(),v.end(),compareInterval);
	
	int aux = a,
	    res = 0;
	
	for(int j = 0; j < v.size(); j++)
	 if(v[j].a <= i.a)
	  if(v[j].b > aux)
	   aux = v[j].b;
	 else if(aux <= i.a)
	  return -1; //nu se poate
	 else{
	 	res++;
		if(aux >= i.b)
		 return res;
		else
		 i.a = aux;
	 }
	
	return -1;
	
}


/////////////////////////////////////////////////////////////////////////////////
//cautare statistica

void swap(vector<int>& v, int i, int j){
	int tmp = v[i]; v[i] = v[j]; v[j] = tmp;
}

//C(n) = n + C(n/5) + C(n/2)
//C(n) <= 100*n
//n + 100*n/5 + 100*n/2 = (1+20+50)*n < 100*n
int cautare_statistica(vector<int>& v, int k);

//mediana medianelor
int choosePivot(vector<int>& v, int lb, int ub){
	
	int n = ub-lb+1,
	    m = (n%5) ? n/5+1 : n/5; //one element every five elements of the interval
	
	vector<int> b(m);
	
	vector<int> tmp;
	for(int i = lb, j = 0; i <= ub; i++){
		tmp.push_back(a[i]);
		if( tmp.size()==5 || i==ub ){ //group completed
		 b[j++] = cautare_statistica(tmp,2);
		 tmp.clear();
		} 
	}
	
	m = cautare_statistica(b,m/2); //mediana in b
	
	for(int i = lb; i<= ub; i++)
	 if(v[i] == m)
	  return i;

}

//impartire
int partition(vector<int>& v, int lb, int ub){
	int i = choosePivot(v,lb,ub);
	swap(v,lb,i);
	int p = ub;//pozitia in care se afla pivotul cand sortam
	for(int j = ub; j > lb; j++)
	 if(v[j] >= v[lb])
	  swap(v,j,p--);
	swap(v,lb,p);
	return p;
}


int cautare_statistica(vector<int>& v, int k, int lb, int ub){
	int p = partition(v,lb,ub);
	if(p == k)
	 return v[k];
	else if(p > k)
	 return cautare_statistica(v,lb,p-1);
	else //p< k
	 return cautare_statistica(v,p+1,ub);
}



int cautare_statistica(vector<int>& v, int k){
  return cautare_statistica(v,k,0,v.size()-1);	
}


/////////////////////////////////////////////////////////////////////////////////
//q-quantile

//reduction to O(q) statistical search: O(qn)
//better: find the statistic (n/q)*(q/2) then divide et impera
// C(n,q) = O(nlog(q)) 

















