#ifndef IMAGE_CONVERTER
#define IMAGE_CONVERTER

#include "ModelGrowCut/BasicTypes.h"
#include "ModelGrowCut/Matrix.h"
#include <QImage>
#include "ModelGrowCut/Cell.h"

namespace ImageConverter
{
    Matrix<float3> getMatrix(QImage img)
    {
        Matrix<float3> res(img.width(), img.height());
        for ( int row = 0; row < img.width(); ++row )
            for ( int col = 0; col < img.height(); ++col )
            {
                QColor clrCurrent( img.pixel( row, col ) );
                res[row][col] = float3(clrCurrent.red(), clrCurrent.green(), clrCurrent.blue());
            }
        return res;
    }

    void saveImage(Matrix<float3>& res, QImage& img)
    {
        for ( int row = 0; row < img.width(); ++row )
            for ( int col = 0; col < img.height() ; ++col )
            {
                img.setPixelColor(row, col, QColor(res[row][col].x, res[row][col].y, res[row][col].z));
            }
    }

    void saveImage(Matrix<Cell> res, QImage& img)
    {
        for ( int row = 0; row < img.width(); ++row )
            for ( int col = 0; col < img.height(); ++col )
            {
             if ((res[row][col].label == background) && (res[row][col].strength > 0)) //background
                {
                     img.setPixelColor(row, col, QColor(255, 255, 255));
                }
             else img.setPixelColor(row, col, QColor(res[row][col].color.x, res[row][col].color.y, res[row][col].color.z));
            }
    }
}

#endif
