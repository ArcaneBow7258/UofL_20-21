#include <stdio.h>
/*
Name: Alvin Tran
Section 2 (B)
Lab #2
Date: 01/24/2021
Description: Asking user for an input to be turned into a double representing some amount in any currency, and, using constants, to convert to another type of currency.
Goal is to familiarize myself in assigning and declaring variables and using the scanf function.

*/

main(){
	//Conversion from USD to X currency

	const double usd_gbp = 0.73; //GBP
	const double usd_cad = 1.27;//CAD
	const double usd_aud = 1.3; //AUD
	const double usd_mxn = 19.89; // Mexican Peso
	const double usd_jpy = 103.75; // japan yen
	const double usd_vnd = 23071.50; // Viet dong
	double base = 0.0;
	
	//Input
	printf("Please enter amount of money to convert (Any unit)");
	scanf("%lf", &base);
	//Base is the amount that will be assigned as the default amount for each currency to convert
	
	//Output: Had to look up how to limit decimanl points to make it look nicer
	printf("    | USD | GBP | CAD | AUD | MXN | JPY | VND | \n");
	printf(" USD|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base*usd_gbp, base*usd_cad, base*usd_aud, base*usd_mxn, base*usd_jpy, base*usd_vnd); 
	printf(" GBP|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base/usd_gbp*usd_gbp, base/usd_gbp*usd_cad, base/usd_gbp*usd_aud, base/usd_gbp*usd_mxn, base/usd_gbp*usd_jpy, base/usd_gbp*usd_vnd ); 
	printf(" CAD|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base/usd_cad*usd_gbp, base/usd_cad*usd_cad, base/usd_cad*usd_aud, base/usd_cad*usd_mxn, base/usd_cad*usd_jpy, base/usd_cad*usd_vnd ); 
	printf(" AUD|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base/usd_aud*usd_gbp, base/usd_aud*usd_cad, base/usd_aud*usd_aud, base/usd_aud*usd_mxn, base/usd_aud*usd_jpy, base/usd_aud*usd_vnd ); 
	printf(" MXN|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base/usd_mxn*usd_gbp, base/usd_mxn*usd_cad, base/usd_mxn*usd_aud, base/usd_mxn*usd_mxn, base/usd_mxn*usd_jpy, base/usd_mxn*usd_vnd ); 
	printf(" JPY|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base/usd_jpy*usd_gbp, base/usd_jpy*usd_cad, base/usd_jpy*usd_aud, base/usd_jpy*usd_mxn, base/usd_jpy*usd_jpy, base/usd_jpy*usd_vnd ); 
	printf(" VND|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf|%.2lf| \n", base, base/usd_vnd*usd_gbp, base/usd_vnd*usd_cad, base/usd_vnd*usd_aud, base/usd_vnd*usd_mxn, base/usd_vnd*usd_jpy, base/usd_vnd*usd_vnd ); 
	//Unfortunately due to unit spacing and the fact I'm spacing my table with spaces rather than dynamically, the talbe will look off depending on the amount of currency in each box
}
