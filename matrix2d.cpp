#include "matrix2d.h"

template class Matrix2D<float>;
template class Matrix2D<double>;
template class Matrix2D<uint8_t>;
template class Matrix2D<uint16_t>;
template class Matrix2D<uint32_t>;
template class Matrix2D<uint64_t>;
template class Matrix2D<int8_t>;
template class Matrix2D<int16_t>;
template class Matrix2D<int32_t>;
template class Matrix2D<int64_t>;

// Please check the state of the NDEBUG definition for properly assertions use

template<typename T>
Matrix2D<T>::Matrix2D(size_t x, size_t y, bool zeroInit)
{
   assert(x>0 && y>0);
   pX=x; pY=y;
   pCount=pX*pY;
   pSize=pCount*sizeof(T);

   if(zeroInit) pData=new T[pCount](); else pData=new T[pCount];
}

template<typename T>
Matrix2D<T>::Matrix2D(const Matrix2D &matrix)
{
   pX=matrix.pX; pY=matrix.pY; pCount=matrix.pCount; pSize=matrix.pSize;
   assert(matrix.pData!=nullptr);
   pData=new T[pCount];
   std::memcpy(pData,matrix.pData,pSize);
}

template<typename T>
Matrix2D<T> &Matrix2D<T>::operator=(const Matrix2D &matrix)
{
   pX=matrix.pX; pY=matrix.pY; pCount=matrix.pCount; pSize=matrix.pSize;
   assert(matrix.pData!=nullptr);
   if(pData) delete[] pData;
   pData=new T[pCount];
   std::memcpy(pData,matrix.pData,pSize);
   return *this;
}

template<typename T>
Matrix2D<T>::~Matrix2D()
{
   if(pData) delete[] pData;
}

template<typename T>
size_t Matrix2D<T>::xSize() const
{
   return pX;
}

template<typename T>
size_t Matrix2D<T>::ySize() const
{
   return pY;
}

template<typename T>
size_t Matrix2D<T>::count() const
{
   return pCount;
}

template<typename T>
size_t Matrix2D<T>::size() const
{
   return pCount;
}

template<typename T>
size_t Matrix2D<T>::bytesSize() const
{
   return pSize;
}

template<typename T>
void Matrix2D<T>::clear()
{
   assert(pData!=nullptr);
   for(size_t i=0;i<pCount;i++) pData[i]=0;
}

template<typename T>
void Matrix2D<T>::fill(T value)
{
   assert(pData!=nullptr);
   for(size_t i=0;i<pCount;i++) pData[i]=value;
}

template<typename T>
T Matrix2D<T>::min() const
{
   assert(pData!=nullptr);
   T min=std::numeric_limits<T>::max(); T value;
   for(size_t i=0;i<pCount;i++)
   {
      value=pData[i];
      if(value<min) min=value;
   }
   return min;
}

template<typename T>
T Matrix2D<T>::max() const
{
   assert(pData!=nullptr);
   T max=std::numeric_limits<T>::lowest(); T value;
   for(size_t i=0;i<pCount;i++)
   {
      value=pData[i];
      if(value>max) max=value;
   }
   return max;
}

template<>
float Matrix2D<float>::sum() const
{
   assert(pData!=nullptr);
   float sum=0.0f;
   for(size_t i=0;i<pCount;i++) sum+=pData[i];
   return sum;
}

template<>
double Matrix2D<double>::sum() const
{
   assert(pData!=nullptr);
   double sum=0.0f;
   for(size_t i=0;i<pCount;i++) sum+=pData[i];
   return sum;
}

template<>
float Matrix2D<float>::avg() const
{
   return sum()/(float)pCount;
}

template<>
double Matrix2D<double>::avg() const
{
   return sum()/(double)pCount;
}

template<typename T>
T *Matrix2D<T>::data()
{
   assert(pData!=nullptr);
   return pData;
}

template<typename T>
T &Matrix2D<T>::operator()(size_t x, size_t y)
{
   assert(x>=0 && x<pX && y>=0 && y<pY);
   assert(pData!=nullptr);
   return pData[y*pX+x];
}

template<typename T>
const T Matrix2D<T>::operator()(size_t x, size_t y) const
{
   assert(x>=0 && x<pX && y>=0 && y<pY);
   assert(pData!=nullptr);
   return pData[y*pX+x];
}
