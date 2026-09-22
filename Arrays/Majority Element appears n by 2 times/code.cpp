int majorityElement(vector<int>arr){
    int candidate = 0;
	int count  =0;
	
	for(int i=0;i<arr.size();i++){
	    if(count == 0){
		    candidate = arr[i];
			count++;
		} 
		else if(candidate == arr[i]){
		     count++;
		} else{
		     count--;
		}
	}
	
	int occurrences = 0;

	for (int num : arr)
	{
		if (num == candidate)
			occurrences++;
	}

	if (occurrences > arr.size() / 2)
		return candidate;

	return -1;
}

Time  = O(n) + O(n) = O(n)
Space = O(1)
