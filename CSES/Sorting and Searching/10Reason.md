# Reason for the working:
See that `curr_num` means that we can make 1,2,3, upto `curr_num` - 1 as a subset of numbers upto i
Now if we have a[i] then we can make a[i],a[i]+1,a[i]+2,...upto a[i] +current number. In order to not miss any number we must have a[i]<= `curr_num`-1