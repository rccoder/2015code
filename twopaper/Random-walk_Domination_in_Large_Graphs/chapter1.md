#本文解决了什么问题？

---

##大图两种随机游走支配集问题的生成

###1.在L随机游走中从其他节点开始向目标节点k的命中中总命中时间是最小的
###2.在L的随机游走中找到k节点最大限度的打击任何一个目标节点的预期数量

#采用什么思想解决这个问题？
---
##动态规划（DP）+贪心（Greedy） ——> 基于贪心的动态规划
一般来说，基于DP的贪心由于昂贵的边缘收益导致不是非常有效。在这篇文章中，提出了一个基于随机取样技术上的，精心设计的一个近似贪心算法，拥有线性的时间复杂度，并且在图的空间大小上也保证了最佳性。

#几个实际应用的例子
---
##1. 在社交网络中项目安放位置问题（Item-placement Problem in online social networks）
在人们的日常社交网络活动中，人们通过浏览网页获得信息。而作为一个用户，去发现其他的信息是需要靠自己的社会联系来完成的。比如在一个照片分享的网站上，用户可以在他的主页上看见他的朋友的照片，一旦用户抵达他的朋友的主页上，他就能够在他的朋友的主页上看到他的朋友的照片。换句话说，下一次要访问的主页完全取决了现在所访问的主页。因此，用户的访问网站过程可以认为是一个在社交网络上的随机游走问题，在这个问题的背后，又有一个比较隐含的限制就是时间上的限制，即用户不可能有无限的时间去浏览朋友的主页或者说是朋友的朋友的网页。

于是，我们就可以通过每个用户在社交网络中可以访问L多的主页地址建立一个L随机游走的模型。基于用户浏览网页的行为出现了两个比较有趣的问题：1.如何去放置这些东西才能让其他的用户比较董怡的通过浏览网页发现他们 2. 如何去放置这些东西才能更多的用户可以找到他们。

举个更加具体的例子，在facebook中，有个APP的开发者想通过facebook让更多的人使用上他的应用，于是，他需要选择k个人去安装他的应用，如过有人安装了他的应用，那么这个人在facebook上的朋友就可以子啊facebook上看他安装这个应用的消息。因此，最开始摆在面前的问题就是如何去选择这k个人的问题，即如何去选择这k个人才能让更多的人去看到这个应用。我们也可以就这个问题建立一个L随机游走的模型。

##2. 网络中优化广告位置问题（Optimizing Ads-placement in advertisement networks）

和前面的例子类似，如何把广告投递给普通人（会支付一些报酬）能让更多的人看到这个广告。我们可以就这个“用户-信息-发现”这一个广告传播过程建立一个L随机游走问题模型

##3. 在p2p网络中资源的加速搜寻问题(Accelerating resources search in P2P networks)

在p2p网络中，如何去安置资源在一小部分人上才能让其他的人也快速的找到资源通过这种预先指定的策略。在P2P网络中，普通用户搜索资源的这种策略是基于随机游走的。于此同时，更为重要的是，对于每个用户所下载的资源，都应该有一个时间使用期，即在这个时间之内是要向别人去分享资源的，超出这个时间之后就不再继续提供资源。因此，我们也就可以以这个p2p资源搜索问题建立一个L随机游走的模型。同时，运用这篇文章中所提到的方法能更加容易的优化这种策略。

