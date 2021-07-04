#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class WeightGreater
{
public:
    // Determine priority.
    bool operator()(const T &a, const T &b) const
    {
        return a.Weight() > b.Weight();
    }

    bool operator()(const T *a, const T *b) const
    {
        return a->Weight() > b->Weight();
    }
};

template <class T>
class WeightLess
{
public:
    // Determine priority.
    bool operator()(const T &a, const T &b) const
    {
        return a.Weight() < b.Weight();
    }

    bool operator()(const T *a, const T *b) const
    {
        return a->Weight() < b->Weight();
    }
};

//////////////////////////////////////////////////////////////////////////
// A class for the object deletion
//////////////////////////////////////////////////////////////////////////
template <class T>
class DeleteFunc
{
public:
    void operator()(const T *it) const
    {
        delete it;
    }
};

/**************************************************************************
*  BaseVertex
*  <TODO: insert class description here>
*
*
*  @remarks <TODO: insert remarks here>
*
*  @author Yan Qi @date 6/6/2010
**************************************************************************/
class BaseVertex
{
    int m_nID;
    double m_dWeight;

public:
    int getID() const { return m_nID; }
    void setID(int ID_) { m_nID = ID_; }

    double Weight() const { return m_dWeight; }
    void Weight(double val) { m_dWeight = val; }

    void PrintOut(std::ostream &out_stream)
    {
        out_stream << m_nID;
    }
};

/**************************************************************************
*  BasePath
*  <TODO: insert class description here>
*
*
*  @remarks <TODO: insert remarks here>
*
*  @author Yan Qi @date 6/6/2010
**************************************************************************/
class BasePath
{
protected:
    int m_nLength;
    double m_dWeight;
    std::vector<BaseVertex *> m_vtVertexList;

public:
    BasePath(const std::vector<BaseVertex *> &vertex_list, double weight)
        : m_dWeight(weight)
    {
        m_vtVertexList.assign(vertex_list.begin(), vertex_list.end());
        m_nLength = m_vtVertexList.size();
    }
    ~BasePath(void) {}

    double Weight() const { return m_dWeight; }
    void Weight(double val) { m_dWeight = val; }

    int length() { return m_nLength; }

    BaseVertex *GetVertex(int i)
    {
        return m_vtVertexList.at(i);
    }

    bool SubPath(std::vector<BaseVertex *> &sub_path, BaseVertex *ending_vertex_pt)
    {

        for (std::vector<BaseVertex *>::const_iterator pos = m_vtVertexList.begin();
             pos != m_vtVertexList.end(); ++pos)
        {
            if (*pos != ending_vertex_pt)
            {
                sub_path.push_back(*pos);
            }
            else
            {
                //break;
                return true;
            }
        }

        return false;
    }

    // display the content
    void PrintOut(std::ostream &out_stream) const
    {
        out_stream << "Cost: " << m_dWeight << " Length: " << m_vtVertexList.size() << std::endl;
        for (std::vector<BaseVertex *>::const_iterator pos = m_vtVertexList.begin(); pos != m_vtVertexList.end(); ++pos)
        {
            (*pos)->PrintOut(out_stream);
            out_stream << "->";
        }
        out_stream << std::endl
                   << "*********************************************" << std::endl;
    }
};
class Path : public BasePath
{
public:
    Path(const std::vector<BaseVertex *> &vertex_list, double weight) : BasePath(vertex_list, weight) {}

    // display the content
    void PrintOut(std::ostream &out_stream) const
    {
        out_stream << "Cost: " << m_dWeight << " Length: " << m_vtVertexList.size() << std::endl;
        for (std::vector<BaseVertex *>::const_iterator pos = m_vtVertexList.begin(); pos != m_vtVertexList.end(); ++pos)
        {
            out_stream << (*pos)->getID() << " ";
        }
        out_stream << std::endl
                   << "*********************************************" << std::endl;
    }
};

class Graph
{
public: // members
    const static double DISCONNECT;

    typedef set<BaseVertex *>::iterator VertexPtSetIterator;
    typedef map<BaseVertex *, set<BaseVertex *> *>::iterator BaseVertexPt2SetMapIterator;

protected: // members
    // Basic information
    map<BaseVertex *, set<BaseVertex *> *> m_mpFanoutVertices;
    map<BaseVertex *, set<BaseVertex *> *> m_mpFaninVertices;
    map<int, double> m_mpEdgeCodeWeight;
    vector<BaseVertex *> m_vtVertices;
    int m_nEdgeNum;
    int m_nVertexNum;

    map<int, BaseVertex *> m_mpVertexIndex;

    // Members for graph modification
    set<int> m_stRemovedVertexIds;
    set<pair<int, int>> m_stRemovedEdge;

public:
    // Constructors and Destructor
    Graph(const string &file_name);
    Graph(const Graph &rGraph);
    ~Graph(void);

    void clear();

    BaseVertex *get_vertex(int node_id);

    int get_edge_code(const BaseVertex *start_vertex_pt, const BaseVertex *end_vertex_pt) const;
    set<BaseVertex *> *get_vertex_set_pt(BaseVertex *vertex_, map<BaseVertex *, set<BaseVertex *> *> &vertex_container_index);

    double get_original_edge_weight(const BaseVertex *source, const BaseVertex *sink);

    double get_edge_weight(const BaseVertex *source, const BaseVertex *sink);
    void get_adjacent_vertices(BaseVertex *vertex, set<BaseVertex *> &vertex_set);
    void get_precedent_vertices(BaseVertex *vertex, set<BaseVertex *> &vertex_set);

    /// Methods for changing graph
    void remove_edge(const pair<int, int> edge)
    {
        m_stRemovedEdge.insert(edge);
    }

    void remove_vertex(const int vertex_id)
    {
        m_stRemovedVertexIds.insert(vertex_id);
    }

    void recover_removed_edges()
    {
        m_stRemovedEdge.clear();
    }

    void recover_removed_vertices()
    {
        m_stRemovedVertexIds.clear();
    }

    void recover_removed_edge(const pair<int, int> edge)
    {
        m_stRemovedEdge.erase(m_stRemovedEdge.find(edge));
    }

    void recover_removed_vertex(int vertex_id)
    {
        m_stRemovedVertexIds.erase(m_stRemovedVertexIds.find(vertex_id));
    }

private:
    void _import_from_file(const std::string &file_name);
};
class DijkstraShortestPathAlg
{
private: // members
    Graph *m_pDirectGraph;

    std::map<BaseVertex *, double> m_mpStartDistanceIndex;
    std::map<BaseVertex *, BaseVertex *> m_mpPredecessorVertex;

    std::set<int> m_stDeterminedVertices;

    std::multiset<BaseVertex *, WeightLess<BaseVertex>> m_quCandidateVertices;

public:
    DijkstraShortestPathAlg(Graph *pGraph) : m_pDirectGraph(pGraph) {}
    ~DijkstraShortestPathAlg(void) { clear(); }

    void clear();

    BasePath *get_shortest_path(BaseVertex *source, BaseVertex *sink);

    void set_predecessor_vertex(BaseVertex *vt1, BaseVertex *vt2)
    {
        m_mpPredecessorVertex[vt1] = vt2;
    }

    double get_start_distance_at(BaseVertex *vertex)
    {
        return m_mpStartDistanceIndex.find(vertex)->second;
    }

    void set_start_distance_at(BaseVertex *vertex, double weight)
    {
        m_mpStartDistanceIndex[vertex] = weight;
    }

    void get_shortest_path_flower(BaseVertex *root)
    {
        determine_shortest_paths(NULL, root, false);
    }

    // The following two methods are prepared for the top-k shortest paths algorithm
    BasePath *update_cost_forward(BaseVertex *vertex);
    void correct_cost_backward(BaseVertex *vertex);

protected:
    void determine_shortest_paths(BaseVertex *source, BaseVertex *sink, bool is_source2sink);

    void improve2vertex(BaseVertex *cur_vertex_pt, bool is_source2sink);
};
class YenTopKShortestPathsAlg
{
    Graph *m_pGraph;

    vector<BasePath *> m_vResultList;
    map<BasePath *, BaseVertex *> m_mpDerivationVertexIndex;
    multiset<BasePath *, WeightLess<BasePath>> m_quPathCandidates;

    BaseVertex *m_pSourceVertex;
    BaseVertex *m_pTargetVertex;

    int m_nGeneratedPathNum;

private:
    void _init();

public:
    YenTopKShortestPathsAlg(const Graph &graph)
    {
        YenTopKShortestPathsAlg(graph, NULL, NULL);
    }

    YenTopKShortestPathsAlg(const Graph &graph, BaseVertex *pSource, BaseVertex *pTarget)
        : m_pSourceVertex(pSource), m_pTargetVertex(pTarget)
    {
        m_pGraph = new Graph(graph);
        _init();
    }

    ~YenTopKShortestPathsAlg(void) { clear(); }

    void clear();
    bool has_next();
    BasePath *next();

    BasePath *get_shortest_path(BaseVertex *pSource, BaseVertex *pTarget);
    void get_shortest_paths(BaseVertex *pSource, BaseVertex *pTarget, int top_k,
                            vector<BasePath *> &);
};
void YenTopKShortestPathsAlg::clear()
{
    m_nGeneratedPathNum = 0;
    m_mpDerivationVertexIndex.clear();
    m_vResultList.clear();
    m_quPathCandidates.clear();
}

void YenTopKShortestPathsAlg::_init()
{
    clear();
    if (m_pSourceVertex != NULL && m_pTargetVertex != NULL)
    {
        BasePath *pShortestPath = get_shortest_path(m_pSourceVertex, m_pTargetVertex);
        if (pShortestPath != NULL && pShortestPath->length() > 1)
        {
            m_quPathCandidates.insert(pShortestPath);
            m_mpDerivationVertexIndex[pShortestPath] = m_pSourceVertex;
        }
    }
}

BasePath *YenTopKShortestPathsAlg::get_shortest_path(BaseVertex *pSource, BaseVertex *pTarget)
{
    DijkstraShortestPathAlg dijkstra_alg(m_pGraph);
    return dijkstra_alg.get_shortest_path(pSource, pTarget);
}

bool YenTopKShortestPathsAlg::has_next()
{
    return !m_quPathCandidates.empty();
}

BasePath *YenTopKShortestPathsAlg::next()
{
    //1. Prepare for removing vertices and arcs
    BasePath *cur_path = *(m_quPathCandidates.begin()); //m_quPathCandidates.top();

    //m_quPathCandidates.pop();
    m_quPathCandidates.erase(m_quPathCandidates.begin());
    m_vResultList.push_back(cur_path);

    int count = m_vResultList.size();

    BaseVertex *cur_derivation_pt = m_mpDerivationVertexIndex.find(cur_path)->second;
    vector<BaseVertex *> sub_path_of_derivation_pt;
    cur_path->SubPath(sub_path_of_derivation_pt, cur_derivation_pt);
    int sub_path_length = sub_path_of_derivation_pt.size();

    //2. Remove the vertices and arcs in the graph
    for (int i = 0; i < count - 1; ++i)
    {
        BasePath *cur_result_path = m_vResultList.at(i);
        vector<BaseVertex *> cur_result_sub_path_of_derivation_pt;

        if (!cur_result_path->SubPath(cur_result_sub_path_of_derivation_pt, cur_derivation_pt))
            continue;

        if (sub_path_length != cur_result_sub_path_of_derivation_pt.size())
            continue;

        bool is_equal = true;
        for (int i = 0; i < sub_path_length; ++i)
        {
            if (sub_path_of_derivation_pt.at(i) != cur_result_sub_path_of_derivation_pt.at(i))
            {
                is_equal = false;
                break;
            }
        }
        if (!is_equal)
            continue;

        //
        BaseVertex *cur_succ_vertex = cur_result_path->GetVertex(sub_path_length + 1);
        m_pGraph->remove_edge(make_pair(cur_derivation_pt->getID(), cur_succ_vertex->getID()));
    }

    //2.1 remove vertices and edges along the current result
    int path_length = cur_path->length();
    for (int i = 0; i < path_length - 1; ++i)
    {
        m_pGraph->remove_vertex(cur_path->GetVertex(i)->getID());
        m_pGraph->remove_edge(make_pair(
            cur_path->GetVertex(i)->getID(), cur_path->GetVertex(i + 1)->getID()));
    }

    //3. Calculate the shortest tree rooted at target vertex in the graph
    DijkstraShortestPathAlg reverse_tree(m_pGraph);
    reverse_tree.get_shortest_path_flower(m_pTargetVertex);

    //4. Recover the deleted vertices and update the cost and identify the new candidates results
    bool is_done = false;
    for (int i = path_length - 2; i >= 0 && !is_done; --i)
    {
        //4.1 Get the vertex to be recovered
        BaseVertex *cur_recover_vertex = cur_path->GetVertex(i);
        m_pGraph->recover_removed_vertex(cur_recover_vertex->getID());

        //4.2 Check if we should stop continuing in the next iteration
        if (cur_recover_vertex->getID() == cur_derivation_pt->getID())
        {
            is_done = true;
        }

        //4.3 Calculate cost using forward star form
        BasePath *sub_path = reverse_tree.update_cost_forward(cur_recover_vertex);

        //4.4 Get one candidate result if possible
        if (sub_path != NULL)
        {
            ++m_nGeneratedPathNum;

            //4.4.1 Get the prefix from the concerned path
            double cost = 0;
            reverse_tree.correct_cost_backward(cur_recover_vertex);

            vector<BaseVertex *> pre_path_list;
            for (int j = 0; j < path_length; ++j)
            {
                BaseVertex *cur_vertex = cur_path->GetVertex(j);
                if (cur_vertex->getID() == cur_recover_vertex->getID())
                {
                    //j = path_length;
                    break;
                }
                else
                {
                    cost += m_pGraph->get_original_edge_weight(
                        cur_path->GetVertex(j), cur_path->GetVertex(1 + j));
                    pre_path_list.push_back(cur_vertex);
                }
            }
            //
            for (int j = 0; j < sub_path->length(); ++j)
            {
                pre_path_list.push_back(sub_path->GetVertex(j));
            }

            //4.4.2 Compose a candidate
            double weight_cost = cost + sub_path->Weight();
            delete sub_path;
            sub_path = new Path(pre_path_list, weight_cost);

            //4.4.3 Put it in the candidate pool if new
            if (m_mpDerivationVertexIndex.find(sub_path) == m_mpDerivationVertexIndex.end())
            {
                m_quPathCandidates.insert(sub_path);
                m_mpDerivationVertexIndex[sub_path] = cur_recover_vertex;
            }
        }

        //4.5 Restore the edge
        BaseVertex *succ_vertex = cur_path->GetVertex(i + 1);
        m_pGraph->recover_removed_edge(make_pair(cur_recover_vertex->getID(), succ_vertex->getID()));

        //4.6 Update cost if necessary
        double cost_1 = m_pGraph->get_edge_weight(cur_recover_vertex, succ_vertex) + reverse_tree.get_start_distance_at(succ_vertex);

        if (reverse_tree.get_start_distance_at(cur_recover_vertex) > cost_1)
        {
            reverse_tree.set_start_distance_at(cur_recover_vertex, cost_1);
            reverse_tree.set_predecessor_vertex(cur_recover_vertex, succ_vertex);
            reverse_tree.correct_cost_backward(cur_recover_vertex);
        }
    }

    //5. Restore everything
    m_pGraph->recover_removed_edges();
    m_pGraph->recover_removed_vertices();

    return cur_path;
}

void YenTopKShortestPathsAlg::get_shortest_paths(BaseVertex *pSource,
                                                 BaseVertex *pTarget, int top_k, vector<BasePath *> &result_list)
{
    m_pSourceVertex = pSource;
    m_pTargetVertex = pTarget;

    _init();
    int count = 0;
    while (has_next() && count < top_k)
    {
        next();
        ++count;
    }

    result_list.assign(m_vResultList.begin(), m_vResultList.end());
}