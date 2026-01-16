## Japan Data Hi-Net

<div>
  <img src="https://img.shields.io/github/last-commit/nahuelmol/japan_data_hinet"/>
  <img src="https://img.shields.io/github/languages/code-size/nahuelmol/japan_data_hinet"/>
  <img src="https://img.shields.io/github/languages/top/nahuelmol/japan_data_hinet"/>
    <img src="https://img.shields.io/github/languages/count/nahuelmol/japan_data_hinet"/>
</div>

Content: most of the documentation is tentative. It's not built yet but it will be soon.
I should mention that data source is K-NET (Kyoshin Network) in specific.

## Index

1.  [Plan](#Plan)
3.  [Extracting Data](#Extracting-data)
4.  [Script cleaner process: from raw data](#Script-cleaner-process:-from-raw-data)
5.  [Proceeding](#Proceeding)
6.  [CMD tool](#CMD-tool)

    5.1 [Asking](#Asking)
    
    5.2 [Checking](#Checking)
    
    5.3 [Display](#Display)

     5.3.1 [Waves](#Waves)
    
     5.3.2 [Maps](#Maps)
    
8.  [Seeding](#Seeding) 
9.  [Building](#Building)       

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
* Tokyo -> March-11 (2011)
* Miyagi -> April-7 (2011)
* Fukushima -> April-17 (2013)
* Fukushima -> April-19 (2013)
* Hokkaido -> September-6 (2018)
* Fukushima -> Febraury-13 (2021)
* Noto -> January-1 (2024)

Initially depth, magnitude, main prefecture, year, among other event's properties are taken into account.

The idea is to integrate as many earthquakes as possible since a more robust data grid is constructed leading to a more precise results. For this process, a software is carried out using a C++, implemented as a CMD application. This is an asistant that analyze data files, collecting information and building a database with SQLite. This allows scalability and the possibility of implemeting continuos integration if a future server-type project is consider.

From each time-series (UD at first) we can get:
* Mean and peak values.
* Patterns in attenuance, deacying, aparent velocity, surface waves, etc that are not that evident during the shaking.

In addition to the database, a table to include is the prefecture/subprefecture-site name as a reference. Each site (or station) has an specific code-name.

|  prefecture  |  prefecture-code  |  siten  | 
|  ----  |  ----  |----  
|  Miyagi  |  MYG  |  1  |
|  Fukushima  |  FKS  |  1  |

The number of sites will inscrease as long as a site is added.

## CMD tool
The main goal is the building of a good CMD tool for managing the constant flow to our database, modifying tables, columns and records. 

The commands listed here are just previsualizations, they are not built yet. The name of the tool is SS.

### Asking

ASK command will give us data about an specific area/zone being a prefecture, subprefecture, etc. 

The following command will show us the number of sites within an specific prefecture.

```
ss ask -p Miyagi sitesn
```

This one, returns data about an specific site if exists or ERR if not.
```
ss ask -st MYG002
```

This print out all earthquakes registered in the database
```
ss ask eqs
```

This add a new earthquake. The format is year-month-day-hour-minutes-seconds without dash.
```
ss add 20110311144600
```
For this is neccesary to have the .knt folder already unzipped in the "data" directory.

### Checking

CHK command works like ASK, it returns data focused on a site. The following gives us which earthquakes were registered by MYG002 as a list ordered by their years. Each earthquake has a unique name, being the complete origin time (from year to second).

```
ss check MYG002 -years
```
This shows a table of two columns, the earthquake name in the first and the requested property on second column. If there's not a property specified then it just returns names. Besides years, can be specified:

* magnitude
* lat
* lon

### Display

### Maps

Using bitmap images it is possible to create an image of Japan and over it paint circles at each site's position and colour it with tone following a value. For example, the max acceleration can be taken. 

First a range of values is established, from minimum to maximum. Later, following the RGB spectra, a given value of acceleartion is translated to a color. Then a map is of values is printed out. The next step could be to paint a map of Japan below the point cloud.

The idea is to replicate what the NIED sied does.

Values used for the mentioned map are scalars extracted from the header of the site ASCII file. However, what matters is getting new values from the wave. Then is needed to add that functionality.

### Waves

It is just a wave plotter. A station and a particular earthquake should be specified. The following command uses the March 11 earthquake wave recorded by MYG002 is used.

```
ss print MYG002 M11-2011
```

GNUplot may possibly be used to generate the time series plots. It is a command line base tool that takes pre shaped data as an input and produces a plot.

### Building intrastructure

Before the data analysis project begins, the structure should be completed including tables ready for their usage. On tables.cpp are specified global tables like earthquakes, stations and records, and their fields can be modified there. Once they're ready, the following command starts the building process on database. 

```
ss db:build
```

In the same script, any other table considered global can be included.

The following command builds specific tables like earthquakes:

```
ss db:build:eqs
```

### Seeding

All data living in our data directory can be saved into the database. It is important to keep in mind how data is organized as tables. An initial aproach follows that:
* Each earthquake will have its own sites table (having just station activity specifically for that earthquake).
* There will be a global station table, just as a register. This can be discarded. However, each station can have its own group of earthquakes that were detected by that station. Then it's mandatory to have them as a unique record asociated to different earthquakes on different times.

The command for this process is:
```
ss db:seed
```

### Db:tasks

Tasks are basic directives that gives specific information about the database. The following displays all earthquakes related to a specific station.

```
ss db:stats -story <statname>
```


### Building

This simple command will compile the code using Makefile

```
mingw32-make
```

