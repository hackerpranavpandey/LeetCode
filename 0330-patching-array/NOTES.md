very easy problem just small analysis is needed

so wo reach element from 1 to n 
let's say I have array=[1,5​] and n=6
then maintain max_reach variable

max_reach=0 initially

now another number is first 1 then max_reach=1
now need 2
so at i=1 nums[i]=5 which is less than max_rach+1

so need to patch 2

now max_reach=max_reach+pached_eklement;
always patch max_reach+1 element

max_reach=1+2=3

now next patch 4

max_reach=7
nums[1]<7

so using some subset of preceding array we can get sum 5

no need for more patching

so traversal entire array and check for two condition initialising max_reach=0 patch=0 
if(nums[i]<=max_reach+1) then no need to patch simply i+=1;
else patching is required
  patch+=1;
  max_reach=max_reach+max_reach+1;

at end return patch


just small thing to keep in mind is that if i exceeds nums.size() so in if contion before checing nums[i]<=max_reach+1 first check if i<nums.size()
