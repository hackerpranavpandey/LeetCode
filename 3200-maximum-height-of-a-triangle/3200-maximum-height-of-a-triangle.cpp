class Solution {
    // so logic is simple at height 0,2,4 and so on use start color for add use second color
private:
    int heightMax(int start,int second){
        int height=0;
        while(start>=0 && second>=0){
            if(height%2==0){
                start-=(height+1);
                if(start<0)
                    break;
                height+=1;
            }
            else{
                second-=(height+1);
                if(second<0)
                    break;
                height+=1;
            }
        }
        return height;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        // its too long to write the code and am doing same thing for two task
        // why not make a function
        // int h1=0;
        // int r=red,b=blue;
        // while(r>=0 && b>=0){
        //     if(h1%2==0){
        //         r=r-(h1+1);
        //         if(r<0)
        //             break;
        //         h1+=1;
        //     }
        //     else{
        //         b-=(h1+1);
        //         if(b<0)
        //             break;
        //         h1+=1;
        //     }
        // }
        // int h2=0;
        // while(red>=0 && blue>=0){
        //     if(h2%2==0){
        //         blue=blue-(h2+1);
        //         if(blue<0)
        //             break;
        //         h2+=1;
        //     }
        //     else{
        //         red-=(h2+1);
        //         if(red<0)
        //             break;
        //         h2+=1;
        //     }
        // }
        // return max(h1,h2);
        return max(heightMax(blue,red),heightMax(red,blue));
    }
};