## japan_data_hinet

### plan
The idea to go through the following stages:

* Data collection
* Storage
* Cleanup
* Transformation
* Analytics
* Insights


Data collection, Storage, Cleanup and Transformation goes from the direct treatment of data, to its shaping to be finally processed and analize. The final part is focused on understanding and giving a meaning to the raw data.

The main analytic method is the Principal Component Analysis (PCA). This way it's possible to find patterns among the great amount of information.

### extracting data
First, I am going to extract data from the NIED site database. 
https://www.bosai.go.jp/e/research/database/earthquake.html

Then, I choose the K-NET tool. There, with an earthquake selected, I have two options
* "Download All Channels Data"
* "Download All Data" (ASCII or binary)

### Script cleaner process: from raw data
Files will be in ascii or binary, then I must check it and shape it to be ready for being storaged in the database.

First, we select an earthquake. In our case, the well known March-11-2011 eartquake. 

![March-11](capture1.png)

The browser will download a tar file which contains our data. The following is just decomprise it.
NIED gives us, a bunch of data, placed in different files. Per station there will a file for each components; UD (up-down), the NS(north-south) and EW(east-west). It's possible to identify what we have by the name of the file.

![March-11](capture3.png)

In our example, you can see (capture1.png) that there is 1227 sites, 1227 stations and each one contains UD, NS and EW data among other information.
Using an .UD file, we can see (capture2.png) how the ascii file looks like, the called K-NET ASCII file. It starts with 17 lines of metadata and from the 18 line a time-series begins which represents the wave in its UD component.

![March-11](capture2.png)


