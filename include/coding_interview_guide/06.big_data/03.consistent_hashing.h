/*
【题目】
工程师经常使用服务器集群来设计和实现数据缓存，以下是常见策略：
1. 无论是添加、查询还是删除数据，都先将数据的id通过哈希函数转换成一个哈希值，记为key；
2. 如果目前存在N台机器，则计算key%N的值，这个值就是该数据所属的机器编号，无论是添加、查询还是删除数据，
  都在这台机器上进行。
请分析这种缓存策略可能带来的问题，并给出改进方案。
*/

/*
【问题分析】
该方案存在的问题是无论是添加还是删除机器，代价都非常高，需要重新计算key%N的值并进行大规模数据迁移。
改进方案：使用一致性哈希算法（一种很好的数据缓存设计方案）。

【一致性哈希算法】
我们假设数据id通过哈希函数计算出的id范围是0~2^32-1，并将该范围想像为一个环。
假设有三台机器，使用哈希函数计算出这三台机器的哈希值，确定机器在环中的位置。
对于输入数据，首先继续使用哈希函数获取哈希值，然后在环中顺时针进行查找，其第一次碰到的机器便为对该数据
进行操作的机器。如下图所示：
         machine1
         /      \
        /        \
       /          \
   machine2----machine3
一致性哈希算法的优势便在于其在添加或者删除机器时，迁移的数据量会非常少。如上图所示，假设我们要删除机器3，
那么只需要将机器3中所有的数据都迁移到机器2中，机器2和机器1中原本的数据不需要移动。

【负载不均情况的处理】
当机器较少时，很可能出现负载不均的情况。解决方案是引入虚拟节点机制。
如上例中，我们可以将3台机器映射为3万个虚拟节点，每一台机器都对应1万个虚拟节点，然后再通过哈希算法将3万个
虚拟节点映射到数据环中。由于哈希算法具有离散性，因此当虚拟节点的数量变多时，节点在哈希算法取值范围内便会分布
地越来越均匀，达到负载均衡的目的。
*/