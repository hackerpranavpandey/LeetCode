class Solution {
public:
     vector<string> below_ten={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    vector<string> below_twenty={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
                  vector<string> below_hundred={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        else if(num<10)
            return below_ten[num];
        else if(num>10 && num<20)
            return below_twenty[(num%10)-1];
        else if(num<100){
            string space="";
            if(num%10){
                space=" ";
            }
            if(num%10==0)
                return below_hundred[num/10];
            return below_hundred[num/10] + space + numberToWords(num%10);
        }
        else if(num<1000){
            string space="";
            if(num%100){
                space=" ";
            }
            if(num%100==0)
                return numberToWords(num/100) + " Hundred";
            return numberToWords(num/100) + " Hundred" + space + numberToWords(num%100);
        }
        else if(num<1000000){
            string space="";
            if(num%100000){
                space=" ";
            }
            if(num%1000==0)
                return numberToWords(num/1000) + " Thousand";
            return numberToWords(num/1000) + " Thousand" + space + numberToWords(num%1000);
        }
        else if(num<1000000000){
            string space="";
            if(num%1000000){
                space=" ";
            }
            if(num%1000000 == 0 )
                return numberToWords(num/1000000) + " Million" ;
            return numberToWords(num/1000000) + " Million" + space + numberToWords(num%1000000);
        }
        else {
            string space="";
            if(num%1000000000){
                space=" ";
            }
            if(num%1000000000==0)
                return numberToWords(num/1000000000) + " Billion";
            return numberToWords(num/1000000000) + " Billion" + space + numberToWords(num%1000000000);
        }
    }
};