## Japan Data Hi-Net

Content: most of the documentation is tentative. It's not built yet but it will be soon.

## Index

1.  [Plan](#Plan)
2.  [Extracting Data](#Extracting-data)
3.  [Script cleaner process: from raw data](#Script-cleaner-process:-from-raw-data)
4.  [Proceeding](#Proceeding)
5.  [CMD tool](#CMD-tool)

    5.1 [Asking](#Asking)
    
    5.2 [Checking](#Checking)
    
    5.3 [Printing](#Printing)

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
First, data is available in the NIED site's database. Specificaly, the K-NET (Kyoshin Network) will be our great provider on this journey. Look at: https://www.bosai.go.jp/e/research/database/earthquake.html

Then, I choose the K-NET tool. Once an earthquake is selected, I have two options
* "Download All Channels Data"
* "Download All Data" (ASCII or binary)
The second option in ASCII is the choosen one.

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

Other table to include is the prefecture/subprefecture-site name. Each site (or station) has an specific code-name. Then it will be created a table containing those data for an easier querying cycle.

|  prefecture  |  prefecture-code  |  siten  | 
|  ----  |  ----  |----  
|  Miyagi  |  MYG  |  1  |
|  Fukushima  |  FKS  |  1  |

The number of sites will inscrease as long as a site is added.

## CMD tool
An specific objective is the building of a good CMD tool for managing the constant flow to our database, modifying tables, columns and records. This is possibly the most important work inside this work.

The commands listed here are just previsualizations, they are not built yet.

### Asking

ASK command will give us data about an specific area/zone being a prefecture, subprefecture, etc. 

The following command will show us the number of sites within an specific prefecture.
```
ask -p Miyagi sitesn
```

This one, returns data about an specific site if exists or ERR if not.
```
ask -st MYG002
```

### Checking

CHK command works like ASK, it returns data, but focused on a site. The following gives us which earthquakes were registered by MYG002 as a list.

```
check MYG002
```

### Printing

It is just a printer of waves. It could be selected an station and its earthquake, but also only the station and all its waves. In our example the March-11 earthquake wave registered by MYG002.

```
print MYG002 M11-2011
```

