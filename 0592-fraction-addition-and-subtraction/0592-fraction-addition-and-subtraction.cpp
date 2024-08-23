class Solution {
private:
    // computing the lcm of to numbers
    int find_lcm(int a,int b){
        if(a%b==0)
            return a;
        else if(b%a==0)
            return b;
        int lcm=a*b,min_num=min(a,b),max_div=1;
        for(int i=2;i<=min_num;i++){
            if(a%i==0 && b%i==0)
                max_div=i;
        }
        return lcm/max_div;
    }
    // then computing the hcf 
     int find_hcf(int a,int b){
        int hcf=1;
        for(int i=2;i<=min(a,b);i++){
            if(a%i==0 && b%i==0)
                hcf=i;
        }
        return hcf;
    }
public:
    string fractionAddition(string expression) {
        // so the idea is very simple first find the numerator and the denominator for each number
        // then find lcm of denominators
        // then like as normal mathematical conversion convert denominator to lcm 
        // also correspondign numerator to the number 
        // by multimplying it with num[i]*lcm/den[i]
        // then sum all the numeratot then divide with hcf of summ and lcm 
        // divide lcm also with the hcf
        // if sum==0 return 0/1 
        // else return sum/lcm
        // stoi("-10") give -10 so no worry for the negative numbers
        vector<int> num,den;
        int i=0,n=expression.size();
        while(i<n){
            string numerator="",denominator="";
            // extract numerator
            while(expression[i]!='/'){
                numerator+=expression[i],i++;
            }
            num.push_back(stoi(numerator));
            i++;
            // then denominator
            while((expression[i]!='+' && expression[i]!='-') && i<n){
                denominator+=expression[i];
                i++;
            }
            den.push_back(stoi(denominator));
        }
        int lcm=den[0];
        for(int i=1;i<den.size();i++){
            lcm=find_lcm(lcm,den[i]);
        }
        // now sum up all the numerators
        int sum=0;
        for(int i=0;i<num.size();i++){
            num[i]=(num[i]*(lcm/den[i]));
            sum+=num[i];
        }
        // in case sum comes out to be 0
        if(sum==0)
            return "0/1";
        int hcf=find_hcf(abs(sum),lcm);
        sum/=hcf,lcm/=hcf;
        return to_string(sum)+"/"+to_string(lcm);
    }
};