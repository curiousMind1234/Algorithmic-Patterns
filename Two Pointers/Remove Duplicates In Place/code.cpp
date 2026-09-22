Given a sorted array, remove duplicates in-place and return the number of unique elements.

Example:
Input:  [1, 1, 2, 2, 3, 4, 4]
Output: 4
Array after modification:
[1, 2, 3, 4, ...]

-----------------------------------------------------------------------------------------------------
  
int removeDuplicates(vector<int>& arr)
{
    int left =0;
	for(int i=1;i<arr.size();i++){
	    if(arr[i]!=arr[left]){
		    left++;
			arr[left] = arr[i];
		} 
	}
	return left + 1;
}

TC: O(N)
SC: O(1)
