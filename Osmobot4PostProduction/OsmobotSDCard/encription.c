//*******************************************************************
// Created Oct 28, 2015
// This file contains all of the encription and decription for sending information to the server.
//*******************************************************************
int32 Publickeye, Publickeyn, Privatekeyd;

//*******************************************************************
//  Created Oct 28, 2015
// This routine detemines if a number is prime.  
// It returns a 1 if it is prime 
// It returns a 0 if is not prime
//*******************************************************************
int isPrime(int32 testedprimenumber)
	{
	int flag = 1;
	int counter, upperlimit;
	float tempnumber;


// Find if the number is prime.  First look to see if it is even.  If it is evan, then it is not a prime number and return.

	if (testedprimenumber & 0x0001)
		{
		//  this means the number is odd.  And it is still possivle for it to be prime.
		// Take the square root of the number and add one to the number to get all of the required numbers to check.
		tempnumber =  (float) testedprimenumber;   // convert to float		
		tempnumber= sqrt(tempnumber) + 1.0;   // take the sqaure root and add one for rounding up to the next number.
		upperlimit =  (int) tempnumber;
		for (counter = 3; counter <= upperlimit; counter=counter+2)   // counter through every other one.  The numbers will be odd.  all even counting numbers are divisable by 2.
			{
			if ((testedprimenumber % counter) == 0)
			//  Check to see if this number has a remainder.  
			// And cycle through all of them to check if there is any one with an evan remainder.
				{
				flag = 0;
				return(flag);//  this fails.
				}
			}
		//	return(flag);  // return with a success because it made it through the whole list.
		}
		else
		{
		// This means the number is even and can not be a prime number.  Return a zero.
		flag = 0;  //  return false.  not a prime number.
		}
    return(flag);
	}



//*************************************************************************
// Created Oct 28, 2015
// This routine makes up a random prime number for encoding.  It also checks to see if it is prime.  The limit has to
// be set on the size of the number.  It needs to be multiplied by another prime number and still
// fit into a 32 bit data type.  Both numbers has to be less than 65532.  
//*************************************************************************

int32 FindRandomPrime(int randomeseed)
	{
	int32 primenumber;
	int trueflag = 0;

	srand(randomeseed);   // Plant the seed into the primenumber generator.  This needs to change each time the routine is called.

	do 
	{
	primenumber=rand();    /// get the random number.  
	//  It needs to be checked if it a prime number.  If it is not a prime number, another one needs to be generated and tested.
	trueflag = isPrime(primenumber);
	}
	while (!trueflag);   // Get out of the loop if it found a prime number.

    return(primenumber);
    }   









//*************************************************************************
// Created Oct 28, 2015
// This is the Extended Euclidean Algorithm routine.  Below is an example to program off.
//Example 2: m = 1239, n = 735
//Step 1: The (usual) Euclidean algorithm:
//(1) 1239 = 1 · 735 + 504
//(2) 735 = 1 · 504 + 231
//(3) 504 = 2 · 231 + 42
//(4) 231 = 5 · 42 + 21
//42 = 2 · 21
//Therefore: gcd(1239, 735) = 21.

//First we use Euclid’s algorithm to find gcd(1124, 84).
//1124 = 84(13) + 32
//84 = 32(2) + 20
//32 = 20(1) + 12
//20 = 12(1) + 8
//12 = 8(1) + 4 ?- (the last nonzero remainder is the answer)
//8 = 4(2) + 0
//We conclude that gcd(1124, 84) = 4.// The result is returned through the function.
// g needs to be greater than t.
//************************************************************************
int32 gcd(int32 g, int32 t)
	{
	
  int32 r;

    /* Check For Proper Input */
    if((g == 0) || (t == 0))
        return(0);
  //  else if((g < 0) || (t < 0))
   //     return(-1);
   if (g == t)
	{
	return(1);  // return false to prevent
	}   
 do
    {
        r = g % t;
        if(r == 0)
            break;
        g = t;
        t = r;
    }
    while(1);
    return (t);
	}


//************************************************************************
// Created Oct 28, 2015
// Find n and f(n).
//  This is the RSA algrothom
// The routine returns nothing, but the data is saved as a global varible.
// the entered number is the seed.  It needs to be changed every time.
//Choose p = 3 and q = 11
//Compute n = p * q = 3 * 11 = 33
//Compute f(n) = (p - 1) * (q - 1) = 2 * 10 = 20
//Choose e such that 1 < e < f(n) and e and n are coprime. Let e = 7
//Compute a value for d such that (d * e) % f(n) = 1. One solution is d = 3 [(3 * 7) % 20 = 1]
//Public key is (e, n) => (7, 33)
//Private key is (d, n) => (3, 33)
//The encryption of m = 2 is c = 27 % 33 = 29
//The decryption of c = 29 is m = 293 % 33 = 2
//************************************************************************
void findthepublickey(int randomeseed)
	{
	
	int32 p,q,functionofn,n,counter,eee,fff,ddd;

	p = FindRandomPrime(randomeseed);  // get the prime number
	q = 173;
	p = 149;
	n = p * q;
    fff = 0;
	functionofn = (p-1)*(q-1);
    for (counter = 3; counter < functionofn; counter = counter + 2)
		{

		if ((gcd(p, counter) == 1) && (gcd(q, counter) == 1) && (gcd(functionofn, counter) == 1))
			{
			eee = counter;
			break;
			}
  		}      
	ddd = (functionofn+1)/eee;

	fff = ddd;		

	}




//*************************************************************************
// Created Nove. 16, 2015
//  Using RSA encryption
//  F(m,k)=m^k mod n   or F(m,k) = pow(m, k) % n
// This routine encryptes a character using the privite key and Totient, and modulus
// The result is a number that is encoded.
//*************************************************************************
int8 encryptchar(int32 modulus, int32 Totient, int key, char message)
	{

	int32 powerdouble,doublemessage;
    int xx;
    int8 resulteddata;
	
// move the paramterts into a float because the power/exp rountine only takes float.


	doublemessage = (int32) message;
// do the power/exp and return it as a double interger.

    powerdouble = doublemessage;   // Set the first muilt.
	for (xx = 2; xx <= key; xx++)
		powerdouble =  doublemessage * powerdouble;


//  do the last part, make the modulus and return the results.
	powerdouble = powerdouble % modulus;
    resulteddata = (int8) powerdouble;   // move into a smaller 
	return(resulteddata);

	}




//******************************************************************************
// Created Nov 16, 2015
// This is the RSA decryption routine 
// F(c,d)=c^ d mod n =  m.   m is the orginal protected number.
// This routine requires the modulus, Totient and the public key to work.
// The result is a character.
//******************************************************************************
char decrypinputnumber(int32 modulus, int privatekey, int code) 
	{

	float powerdouble,doublecode,floatcode,modulusfloat;
    int xx;
	
// move the paramterts into a float because the power/exp rountine only takes float.

	doublecode = (float) privatekey;
	floatcode = (float) code;
    modulusfloat = (float) modulus;
// do the power/exp and return it as a double interger.

	powerdouble = doublecode * log10(floatcode);
	powerdouble = powerdouble - log10(modulusfloat); 
	powerdouble =  pwr(10.0,powerdouble);
//	powerdouble = pwr(floatcode,doublecode);

//  do the last part, make the modulus and return the results.
//	powerdouble = powerdouble % modulus;


	return(code);  
	}