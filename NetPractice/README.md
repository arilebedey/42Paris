### Improved dark-mode NetPractice interface

![Three networks must be distinct and non-overlapping for level 8 routing to work](https://raw.githubusercontent.com/arilebedey/42Paris/main/NetPractice/screenshot.png)

### Routing

A router links one or more networks. Networks must be distinct and non-overlapping for routing to work.

### Useful table for block sizes

| CIDR | Block size | Total hosts | Usable hosts | Network address | Broadcast address | Number of blocks (in 256) |
| ---- | ---------- | ----------- | ------------ | --------------- | ----------------- | ------------------------- |
| /32  | 255        | 1           | 0            | all 0s          | all 1s            | 256                       |
| /31  | 254        | 2           | 0            | first IP        | last IP           | 128                       |
| /30  | 252        | 4           | 2            | first IP        | last IP           | 64                        |
| /29  | 248        | 8           | 6            | first IP        | last IP           | 32                        |
| /28  | 240        | 16          | 14           | first IP        | last IP           | 16                        |
| /27  | 224        | 32          | 30           | first IP        | last IP           | 8                         |
| /26  | 192        | 64          | 62           | first IP        | last IP           | 4                         |
| /25  | 128        | 128         | 126          | first IP        | last IP           | 2                         |
| /24  | 0          | 256         | 254          | first IP        | last IP           | 1                         |

### Reserved IPs

| Range              | Prefix                      | Description                              |
| ------------------ | --------------------------- | ---------------------------------------- |
| 0.0.0.0/8          | 0.0.0.0–0.255.255.255       | "This" network (used for default routes) |
| 10.0.0.0/8         | 10.0.0.0–10.255.255.255     | Private network                          |
| 100.64.0.0/10      | 100.64.0.0–100.127.255.255  | Shared address space (Carrier NAT)       |
| 127.0.0.0/8        | 127.0.0.0–127.255.255.255   | Loopback addresses                       |
| 169.254.0.0/16     | 169.254.0.0–169.254.255.255 | Link-local (APIPA)                       |
| 172.16.0.0/12      | 172.16.0.0–172.31.255.255   | Private network                          |
| 192.0.0.0/24       | 192.0.0.0–192.0.0.255       | IETF protocol assignments                |
| 192.0.2.0/24       | 192.0.2.0–192.0.2.255       | TEST-NET-1 (documentation/testing)       |
| 192.88.99.0/24     | 192.88.99.0–192.88.99.255   | IPv6 to IPv4 relay (deprecated)          |
| 192.168.0.0/16     | 192.168.0.0–192.168.255.255 | Private network                          |
| 198.18.0.0/15      | 198.18.0.0–198.19.255.255   | Network benchmark testing                |
| 198.51.100.0/24    | 198.51.100.0–198.51.100.255 | TEST-NET-2 (documentation/testing)       |
| 203.0.113.0/24     | 203.0.113.0–203.0.113.255   | TEST-NET-3 (documentation/testing)       |
| 224.0.0.0/4        | 224.0.0.0–239.255.255.255   | Multicast addresses                      |
| 240.0.0.0/4        | 240.0.0.0–255.255.255.254   | Reserved for future use                  |
| 255.255.255.255/32 | 255.255.255.255             | Limited broadcast address                |
