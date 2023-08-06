class BrowserHistory {
public:
    vector<string> visitedURL;
    int cururl,lasturl;
    BrowserHistory(string homepage) {
        visitedURL.push_back(homepage);
        cururl=0,lasturl=0;
    }
    
    void visit(string url) {
        cururl +=1;
        if(visitedURL.size()>cururl){
            visitedURL[cururl]=url;
        }
        else{
            visitedURL.push_back(url);
        }
        
        lasturl=cururl;
    }
    
    string back(int steps) {
        cururl=max(0,cururl-steps);
        return visitedURL[cururl];
    }
    
    string forward(int steps) {
        cururl=min(lasturl,cururl+steps);
        return visitedURL[cururl];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */