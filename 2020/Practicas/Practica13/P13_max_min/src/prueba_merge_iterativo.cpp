// Modifacion Iterativa (Probando) 18-01-2021
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::merge_iterativo(void){
  int sz_;
  int left;
  int right;
  int center;

  for(sz_ = 1; sz_ < size(); sz_ *= 2 ){
    for(left = 0; left + sz_ > size(); left += sz_){
      right = left + sz_ -1;
      center = left + sz_/2;
      merge(left, center, right);
    }
  }

}

//  MAIN

    v.merge_iterativo();

    cout << v << endl;


// .hpp 

    void merge_iterativo(void);
