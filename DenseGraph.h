//
// Created by zhangsiqi on 2017/6/8.
//

#ifndef DATASTRUCTUREWORK_DENSEGRAPH_H
#define DATASTRUCTUREWORK_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图 -- 邻接矩阵
class DenseGraph {

private:
    int n, m; // n: 顶点数, m: 边数
    bool directed;  // 用来设置图为有向图还是无向图 true:有向图 false: 无向图
    // 邻接矩阵用二维vector 数组表示 邻接矩阵中存放bool型变量表示是否有边
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {

    }

    // 返回图中的顶点数
    int V() { return n; }

    // 返回图中的边数
    int E() { return m; }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        // 返回true 代表已经有边了  直接结束函数
        if (hasEdge(v, w)) {
            return;
        }

        g[v][w] = true;
        if (!directed) {
            g[w][v] = true;
        }
        m++;  // 边数++
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    class adjIterator {

    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &g, int v) : G(g) {
            this->v = v;
            this->index = -1;
        }

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            // index 先加1 然后遍历小于总顶点数的次数
            for (index += 1; index < G.V(); index++)
                // 如果其中一个顶点为true 则返回顶点索引
                if (G.g[v][index])
                    return index;
            return -1;
        }

        bool end() {
            return index >= G.V();
        }
    };
};


#endif //DATASTRUCTUREWORK_DENSEGRAPH_H
