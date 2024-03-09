from pyspark.sql import SparkSession
from pyspark.sql.functions import count

import time
start_time = time.time()
spark = SparkSession.builder.appName("TransactionCountByCountry").getOrCreate()
df = spark.read.csv("House_Pricing.csv", header=True, inferSchema=True)

transaction_counts = df.groupBy("Country").agg(count("*").alias("Count"))
output_path = "OutputFile.csv"
transaction_counts.write.csv(output_path, header=True, mode="overwrite")

end_time = time.time()

elapsed_time = end_time - start_time
print(f"Execution time: {elapsed_time} seconds")


spark.stop()
