int getSecondLargest(int *arr, int n) {
    // code here
    int largest=arr[0];
    int slargest=-1;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        if(largest>arr[i] && slargest<arr[i]){
            slargest=arr[i];
        }
    }
    return slargest;
}
