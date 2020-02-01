class FileSystem {
    struct Files {
        unordered_map<string, Files*> mapping;
        string name;
        string content;
        bool isFile;
        Files() {
            content = "";
            name = "";
            isFile = false;
        }
    };
    Files *root;
    
    vector<string> split(string &path) {
        vector<string> paths = {"/"};
        if(path == "/")
            return paths;
        
        paths.push_back("");
        for(int i=1; i<path.length(); i++) {
            if(path[i] == '/')
                paths.push_back("");
            else
                paths.back().push_back(path[i]);    
        }    

        return paths;
    }
    
public:
    FileSystem() {
        root = new Files();
        root->mapping["/"] = new Files();
    }
    
    vector<string> ls(string path) {
        Files *curr = root;
        vector<string> paths = split(path);
        
        for(string &p: paths) 
            curr = curr->mapping[p];
        
        vector<string> files;
        if(curr->isFile) {
            files.push_back(curr->name);
        }
        else {
            for(auto &i: curr->mapping)
                files.push_back(i.first);
            sort(files.begin(), files.end());
        }
        
        return files;
    }
    
    void mkdir(string path) {
        vector<string> paths = split(path);
        Files *curr = root;
        
        for(string &p: paths) {
            if(curr->mapping.find(p) == curr->mapping.end())
                curr->mapping[p] = new Files();
            curr = curr->mapping[p];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> paths = split(filePath);
        Files *curr = root;
        
        for(string &p: paths) {
            if(curr->mapping.find(p) == curr->mapping.end())
                curr->mapping[p] = new Files();
            curr = curr->mapping[p];
        }
        
        curr->content.append(content);
        curr->name = paths.back();
        curr->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> paths = split(filePath);
        Files *curr = root;
        
        for(string &p: paths)
            curr = curr->mapping[p];
        
        return curr->content;
    }
};
