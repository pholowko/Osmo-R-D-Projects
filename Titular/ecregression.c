eccalibrationx[0] = 447.0;
eccalibrationx[1] = 44.0;
eccalibrationx[2] = 19.0;


eccalibrationy[0]  = 33.0;
eccalibrationy[1]  = 481.0;
eccalibrationy[2]  = 1718.0;


//******************************************************************************
// Created June 20, 2016
//  Calculate the averages of the x value and the y value
// Find x, y, ?(x2), ?(xy), ?(y2)
//*******************************************************************************


eccalxaverage = (log(eccal1x) + log(eccal2x) + log(eccal3x))/3;
eccalyaverage = (eccal1y  + eccal2y + eccal3y)/3;

//******************************************************************************
//Created June 20, 2016
// Calculate the sum of the products of x times y
//******************************************************************************
sumofproducts = log(eccal1x) * eccal1y + log(eccal2x) * eccal2y + log(eccal3x) * eccal3y;

//******************************************************************************
//Created June 20, 2016
// Calculate the sum of the squares of x 
//******************************************************************************
sumofxsquare = log(eccal1x) * log(eccal1x) + log(eccal2x) * log(eccal2x) + log(eccal3x) * log(eccal3x);
//******************************************************************************
//Created June 20, 2016
// Calculate the sum of the squares of y 
//******************************************************************************
sumofysquare = eccal1y * eccal1y + eccal2y * eccal2y + eccal3y * eccal3y;
nn=3;  // this is the number of data points

//   Find m = [?(xy) - n(x)(y)]/[?(x2) - n(x)2]

mm = (sumofproducts - nn*eccalxaverage*eccalyaverage)/(sumofxsquare-nn*eccalxaverage*eccalxaverage);
//echo ($mm. "<br>");
// find   b = y - mx

bb = eccalyaverage - mm*eccalxaverage;
//echo ($bb. "<br>");
// Calculate the fit ratio      [?(xy) - n(x)(y)]/sqrt[(?(x2) - n(x)2)(?(y2) - n(y)2)]
// Similarly, the equation y = axc can be linearlized to Ln(y) = Ln(a) + cLn(x). This is now linear in the variables Ln(y) and Ln(x). 

}

//*******************************************************************************************
// Created June 21, 2016
//  This function returns the EC calculation for the graphs.  The coefficenst for $bb and $mm need to be run before hand.
//**********************************************************************************************
float findec(inputreading)
{
if (inputreading <= 0.0)
     {
      outputreading = 0.0;
      }
     else
     {
outputreading = mm*log(inputreading) + bb;
   }
//$outputreading =  $inputreading;
return (outputreading);

}
