class Solution {
private:
    int n;
    int t[1001][1001]={-1}; 
    // use simple concept of keeping book at same shelf or next shelf 
    // recursive approach so using mwmoization works well here
    int solve(vector<vector<int>>& books,int rem_width,int shelfWidth,int i,int max_height){
        // keep in same shelf
        if(i>=books.size())
            return max_height;
        if(t[i][rem_width])
            return t[i][rem_width];
        int book_w=books[i][0];
        int book_h=books[i][1];
        int keep=INT_MAX; // if keep on same
        if(book_w<=rem_width){
            keep=solve(books,rem_width-book_w,shelfWidth,i+1,max(max_height,book_h));
        }
        // keep on next shelf
        int skip=max_height+solve(books,shelfWidth-book_w,shelfWidth,i+1,book_h);
        return t[i][rem_width]=min(keep,skip);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // order of placing book should be same as given
        // greedy algorithm will not work here since we want to minimize the height
        // int prev_level=0;  // shelf ke prev level tak height
        // int ans=0;  // shelf ke current level tak height
        // int space_left=shelfWidth;
        // int n=books.size();
        // for(int i=0;i<n;i++){
        //     if((space_left-books[i][0])>=0){
        //         ans=max(ans,(prev_level+books[i][1])); // update the height
        //         space_left-=books[i][0];
        //     }
        //     // when current level does not have enough thickness
        //     else{
        //         space_left=shelfWidth-books[i][0];
        //         prev_level=ans;
        //         ans+=books[i][1];
        //     }
        // }
        // return ans;
        // now lets try out using the concept of dp
        // then for each book we have to decide whether to keep it in same shelf or next height
        // try both recursively and return min of them
        int rem_width=shelfWidth;
        int ans=solve(books,rem_width,shelfWidth,0,0);
        return ans;
    }
};