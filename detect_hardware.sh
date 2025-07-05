#!/bin/bash
export numa_domains=$(lscpu | awk '/^NUMA node\(s\)/ { print $NF }')
export threads_per_numa=$(lscpu | awk '/^CPU\(s\):/ { cpus=$2 } /^NUMA node\(s\)/ { numa_domains=$NF } END { print cpus/numa_domains }')
export threads_per_core=$(lscpu | awk '/^Thread\(s\) per core:/ { threads_per_core=$4 } END { print threads_per_core }')
export cores_per_numa=$(lscpu | awk '/^CPU\(s\):/ { cpus=$2 } /^NUMA node\(s\)/ { numa_domains=$NF } END { print cpus/numa_domains }')
export physical_cores_per_numa=$(echo "scale=0; $cores_per_numa / $threads_per_core" | bc)
export physical_cores=$(echo "scale=0; $physical_cores_per_numa * $numa_domains" | bc)
export logical_cores=$(echo "scale=0; $threads_per_numa * $numa_domains" | bc)

echo $(hostname) " has $numa_domains numa domains and $threads_per_numa logical cores and $physical_cores_per_numa physical cores per domain"
