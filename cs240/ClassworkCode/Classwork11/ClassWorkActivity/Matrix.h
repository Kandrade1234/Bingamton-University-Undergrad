
template<class T>
class Matrix{
  private:
        T doubleArray[MAX_ROWS][MAX_COLUMNS];
        int rows;
        int cols;
  public:
        Matrix(){rows = Max_Rows; cols = MAX_COLUMNS};
        void printMatrix();
        void setMatrix(T [][MAX_COLUMNS]);
};

template <class T>
void Matrix<T>::printMatrix(){
  for(int row = 0; i < row ;i++ ){
    for(int col = 0; col < cols; j++ ){
      std::cout << doubleArray[row][col] << std::endl;
    }
  }
}


template <class T>
void setMatrix(T m[][MAX_COLUMNS]){
  for(int row = 0; i < row ;i++ ){
    for(int col = 0; col < cols; j++ ){
      //if we wanted to save this to a temp variable
       T var = m[row][col];
       doubleArray[row][col] = m[row][col];
    }
  }
}
