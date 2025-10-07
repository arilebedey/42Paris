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
