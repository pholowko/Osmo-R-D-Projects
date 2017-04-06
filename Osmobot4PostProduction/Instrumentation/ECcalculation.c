


float bb,mm;   // this is the offset in the regression
// ************************************************************************************
// Created June 10, 2016
// Get the regression raw data from the Unit serial number table.
// It gets the values and calculates all of the required averages and summations.
//************************************************************************************
void getalleccalibration(void) {

    float nn,eccalxaverage,eccalyaverage,sumofproducts,sumofxsquare,sumofysquare;


//******************************************************************************
// Created June 20, 2016
//  Calculate the averages of the x value and the y value
// Find x, y, ?(x2), ?(xy), ?(y2)
//*******************************************************************************
eccalxaverage = (log(sysInput.eccal1x) + log(sysInput.eccal2x) + log(sysInput.eccal3x))/3;
eccalyaverage = (sysInput.eccal1y  + sysInput.eccal2y + sysInput.eccal3y)/3;

//******************************************************************************
//Created June 20, 2016
// Calculate the sum of the products of x times y
//******************************************************************************
sumofproducts = log(sysInput.eccal1x) * sysInput.eccal1y + log(sysInput.eccal2x) * sysInput.eccal2y + log(sysInput.eccal3x) * sysInput.eccal3y;

//******************************************************************************
//Created June 20, 2016
// Calculate the sum of the squares of x 
//******************************************************************************
sumofxsquare = log(sysInput.eccal1x) * log(sysInput.eccal1x) + log(sysInput.eccal2x) * log(sysInput.eccal2x) + log(sysInput.eccal3x) * log(sysInput.eccal3x);
//******************************************************************************
//Created June 20, 2016
// Calculate the sum of the squares of y 
//******************************************************************************
sumofysquare = sysInput.eccal1y * sysInput.eccal1y + sysInput.eccal2y * sysInput.eccal2y + sysInput.eccal3y * sysInput.eccal3y;
nn=3.0;  // this is the number of data points

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
float findec(float inputreading){

    float outputreading;
    
    getalleccalibration();   // Get the varaibles if they change.  Each time calculation is done, find all of the calibration numbers.
    
if (inputreading <= 0.0)
     {
      outputreading = 0.0;
      }
     else
     {
outputreading = mm*log(inputreading) + bb;
   }
//$outputreading =  $inputreading;
return(outputreading);
}

