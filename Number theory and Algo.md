LCM of (a, b)= (a*b)/GCD(a, b)
LCM of a bunch of numbers can be found by multiplying the each (prime factors^highest power) of all the numbers.

Let, 
N= (a^p)*(b^q)*(c^r)*... where a,b,c are primes and p,q,r are powers
 
Number of divisors of N = (p+1)*(q+1)*(r+1)*...

Number of coprimes less than N= N(1-(N/a))(1-(N/b))(1-(N/c))...

* Two numbers are coprimes when their gcd is 1.
* Therefore, we have to find the numbers whose gcd is not 1 with N
* and these numbers are always multiples of prime factors of N.
* So, if N=p1*p2*p3*...
* Then, number of coprimes of N smaller than N is
* N- (N/p1) - (N/p2) - (N/p3)
* Here, some numbers were cancelled out multiple times.
* For that we have to compensate such that those numbers are cancelled
* one time only. To do that we have to add (N/C) where C is product of 
* prime numbers in different combinations.
 
Sum of factors of N= ((a^(p+1)-1)/(a-1))*((b^(q+1)-1)/(b-1))*(c^(r+1)-1)/(c-1))...
* Or simply, it is the product of geometric sum of primeN till power+1 th term
 
Finding prime factorization within the range of 1-N
Use seive to find primes within sqrt(N) as search limit will hit sqrt(N) when number is N

let n be the number for which to find prime factor
```C++
  let v= n
  for(int j=2; j<=sqrt(v); j+=2){
    if(prime[j] && v%j==0){
    int power=0;
    while(v%(int)pow(j, power+1)==0) power++;  //This gives us current prime^power

      //Do whatever

      v/=(int)pow(j, power); //Divide this to lower our search limit to new sqrt(v)
    }
    if(j==2) j--; 
  }
  if(v!=1) factors++; //If after dividing it number isn't 1, then it is a prime^1
```
                

Legendre’s formula (Given p and n, find the largest x such that p^x divides n!)
x=floor(n/p^1)+floor(n/p^2)+floor(n/p^3)+...

Number of digits in a number
 * ln(ab)= ln(a)+ln(b)
 * Then,
 * ln(n!)=ln(1)+ln(2)+ln(3)+...+ln(n)
 * Now, for the number of digits in n
 * The formula becomes
 * floor(ln(n!))+1
 * => floor(ln(1)+ln(2)+ln(3)+...+ln(n))+1
 * And for different base divide by ln[base]
 * floor(ln(n!)/ln[base])+1= floor((ln(1)+ln(2)+ln(3)+...+ln(n))/ln[base])+1

