class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            int left=0;
            int right=image.size()-1;
            while(left<=right){
                swap(image[i][left],image[i][right]);
                image[i][left]=1-image[i][left];
                if(left!=right){
                    image[i][right]=1-image[i][right];
                }
                left++;
                right--;
            }
        }
        return image;
    }
};