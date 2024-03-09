from pyspark.sql import SparkSession
from pyspark.sql.functions import desc
import time
start_time = time.time()

spark = SparkSession.builder.appName("SecondMostTransactions").getOrCreate()
df = spark.read.csv("House_Pricing.csv", header=True)
grouped_df = df.groupBy("Country").count()
sorted_df = grouped_df.sort(desc("count"))
sec_trans = sorted_df.collect()[1]
country = sec_trans["Country"]
#count = sec_trans["count"]
print(f"Country with the second most transactions is '{country}' ")

end_time = time.time()

elapsed_time = end_time - start_time
print(f"Execution time: {elapsed_time} seconds")

spark.stop()
