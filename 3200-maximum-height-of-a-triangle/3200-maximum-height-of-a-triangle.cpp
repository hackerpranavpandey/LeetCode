class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int h1=0;
        int r=red,b=blue;
        while(r>=0 && b>=0){
            if(h1%2==0){
                r=r-(h1+1);
                if(r<0)
                    break;
                h1+=1;
            }
            else{
                b-=(h1+1);
                if(b<0)
                    break;
                h1+=1;
            }
        }
        int h2=0;
        while(red>=0 && blue>=0){
            if(h2%2==0){
                blue=blue-(h2+1);
                if(blue<0)
                    break;
                h2+=1;
            }
            else{
                red-=(h2+1);
                if(red<0)
                    break;
                h2+=1;
            }
        }
        return max(h1,h2);
    }
};