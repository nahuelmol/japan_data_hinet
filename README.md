## Japan Data Hi-Net

Content

## Index

*   [Plan](#Plan)
*   [Extracting Data](#Extracting-data)
*   [Script cleaner process: from raw data](#Script-cleaner-process:-from-raw-data)
*   [Proceeding](#Proceeding)

### Plan
The following stages are established in order to perform a proper data analysis;

* Data collection
* Storage
* Cleanup
* Transformation
* Analytics
* Insights

Data collection, storage, cleanup, and transformation range from the direct handling of data to its shaping, being finally processed and analized. The final part is focused on understanding and giving a meaning to the raw data.

The main analytical method is Principal Component Analysis (PCA). This approach makes it possible to identify patterns within the large amount of information provided.

### Extracting data
First, I am going to extract data from the NIED site database. 
https://www.bosai.go.jp/e/research/database/earthquake.html

Then, I choose the K-NET tool. Once an earthquake is selected, I have two options
* "Download All Channels Data"
* "Download All Data" (ASCII or binary)

### Script cleaner process: from raw data
Files will be in ASCII or binary format, then I must check and process them in such a way to get them ready for storage in the database.

First, we select an earthquake. In our case, the well known March-11-2011 Tohoku eartquake. 

![March-11](capture1.png)

The browser will download a tar file which contains our data. The following is just decomprise it.
NIED gives us, a bunch of data, placed in different files. Per station there will a file for each components; UD (up-down), the NS(north-south) and EW(east-west). It's possible to identify what we have by the name of the file.(capture2.png)

![March-11](capture2.png)

In our example, you can see (capture1.png) that there are 1.227 sites, 1.227 stations and each one contains UD, NS and EW wave components as time series, along with other information.
Using an .UD file, we can see (capture3.png) how the ASCII file looks like, the called K-NET ASCII file. It starts with 17 lines of metadata and from the 18 line a time-series begins which represents the wave in its UD component.

![March-11](capture3.png)

### Proceeding
There will be a table that contains the studied earthquakes and its most important metadata.

* Geiyo Islands -> March-24 (2001)
* Chuetsu -> October-23 (2004)
* Chuetsu -> July-16 (2007)
* Iwate-Miyagi -> June-14 (2008)
* Miyagi -> April-7 (2011)
* Tokyo -> March-11 (2011)
* Fukushima -> April-17 (2013)
* Fukushima -> April-19 (2013)
* Hokkaido -> September-6 (2018)
* Fukushima -> Febraury-13 (2021)
* Noto -> January-1 (2024)

At the beginning, are considered; depth, magnitude, prefecture, year, etc. This will allow an accurate control over data, paying attention to its integrity.

The best is to include more and more earthquakes. This process will be done using a c++ software for examining each file through a command line tool. This allows scalability, and possibly continuos integration in a future server-type project.

From each time-series (UD at first) we can get:
* Mean and peak values
* Some type of pattern durgin the shaking like, decaing, attenuance, code, aparent velocity (Cx) role, surface waves presence 
