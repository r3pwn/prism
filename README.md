# What is Prism?
Prism is a class project that aims to use MPI to create an environment that allows for parallelized Rainbow Table generation. It's essentially a wrapper for rtgen.

# Compiling
Just run `make all` to make, and `make clean` to clean up the mess.

# Usage
Compile, then run `prism-bsub.sh`. This may take some time. You can now use it to guess nearly any 7-letter lowercase password.

For our example, we will use "pazwurd".

```
$ ./prism-md5hash.sh pazwurd
MD5 hash of pazwurd is:
8cffc3c5add3ffcc575720c2627ccf97  -
```
Here we get the md5 hash of the password, so now we can try to crack that using the tables we generated earlier.
```
$ ./prism-crack.sh 8cffc3c5add3ffcc575720c2627ccf97
md5_loweralpha#7-7_0_100x67108863_idea-demo.rt:
1041121280 bytes read, disk access time: 0.27 s
verifying the file...
searching for 1 hash...
plaintext of 8cffc3c5add3ffcc575720c2627ccf97 is pazwurd
cryptanalysis time: 0.00 s

statistics
-------------------------------------------------------
plaintext found:          1 of 1 (100.00%)
total disk access time:   0.27 s
total cryptanalysis time: 0.00 s
total chain walk step:    1081
total false alarm:        14
total chain walk step due to false alarm: 974

result
-------------------------------------------------------
8cffc3c5add3ffcc575720c2627ccf97  pazwurd  hex:70617a77757264
```
And we can see that our password was cracked in 0.27s

# Why are you including binary copies of rtgen?
It's a long story. Partially due to time constraints, partially due to certain pieces of technology being a pain. Trust me, I'm not a fan of it, either.