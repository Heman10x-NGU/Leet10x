class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
          return 0;
        }

        int i=0;

        for(int j=1;j<nums.size();j++){
          if(nums[i]!=nums[j]){
            //found an element which is not equal to current
            i++;
            //and now change the next element to the org element
            // as we did i++;
            nums[i]=nums[j];
            //keeping the unequal element
            // just after the previous unique element
          }
        }
        //where the loop stop i will be at the
        //position which has the last unqiue char
        // since 0 based indexing

        return i+1;
    }
};