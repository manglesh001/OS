from pyspark.sql import SparkSession
from pyspark.sql.functions import col
import time
st = time.time()

spark = SparkSession.builder.appName("SecondHighestPrice").getOrCreate()
df = spark.read.csv("House_Pricing.csv", header=True, inferSchema=True)
countrys = ['GREATER LONDON', 'CLEVELAND', 'ESSEX']

filtered_df = df.filter(col('Country').isin(countrys))
sorted_df = filtered_df.sort(col('Price').desc())
sec_high = sorted_df.collect()[1]
price = sec_high['Price']
country = sec_high['Country']
print(f"Second highest transacted value is {price} which is transacted in {country}.")

end_time = time.time()

elapsed_time = end_time - st
print(f"Execution time: {elapsed_time} seconds")

spark.stop()
