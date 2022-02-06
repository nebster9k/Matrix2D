#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <cstdint>
#include <cstring>
#include <limits>
#include <cassert>

/**
 * @brief The Matrix2D class represents a convenient two-dimensional values storage in XY-representation
 */
template <typename T>
class Matrix2D
{
   public:
      Matrix2D(size_t x, size_t y=1, bool zeroInit=true);
      Matrix2D(const Matrix2D &matrix);
      Matrix2D &operator=(const Matrix2D &matrix);
      ~Matrix2D();

      T &operator()(size_t x, size_t y=0);
      const T operator()(size_t x, size_t y=0) const;

      size_t xSize() const;
      size_t ySize() const;
      size_t count() const;
      size_t size() const;
      size_t bytesSize() const;

      void clear();
      void fill(T value);

      T min() const;
      T max() const;

      T sum() const;
      T avg() const;

      T *data();

   private:
      size_t pX,pY,pCount,pSize;
      T *pData=nullptr;

   protected:

};

#endif // MATRIX2D_H
