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

### script cleaner
Files will be in ascii or binary format, then I must check it and store data in an acurate format.

Data is saved as accelerations in the three different components; vertical (UD), and both horizontal. There is alsos wave data. Which in our case is not relevant.


