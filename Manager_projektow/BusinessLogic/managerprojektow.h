#ifndef MANAGERPROJEKTOW_H
#define MANAGERPROJEKTOW_H

#include <string>
#include <vector>

using namespace std;


class Project {
protected:
    string name;
    vector<string> technologies;
    string status;
    float workTime;
    string repositoryLink;

public:
    // Konstruktor
    Project(const string& name,
            const vector<string>& technologies,
            const string& status,
            float workTime,
            const string& repositoryLink);

    // Gettery
    string getName() const;
    vector< string> getTechnologies() const;
    string getStatus() const;
    float getWorkTime() const;
    string getRepositoryLink() const;

    // Settery
    void setName(const string& name);
    void setTechnologies(const vector<string>& technologies);
    void setStatus(const string& status);
    void setWorkTime(float time);
    void setRepositoryLink(const string& link);

    // Pozostałe funkcje
    void printInfo() const;
    string toString() const;

    // Destruktor
    virtual ~Project() = default;

};

class TeamProject : public Project {
private:
    vector<string> collaborators;
    string responsibilities;

public:
    // Konstruktor
    TeamProject(const string& name,
                const vector<string>& technologies,
                const string& status,
                float workTime,
                const string& repositoryLink,
                const vector<string>& collaborators,
                const string& responsibilities);

    // Gettery
    const vector<string>& getCollaborators() const;
    const string& getResponsibilities() const;

    // Settery
    void setCollaborators(const vector<string>& collaborators);
    void setResponsibilities(const string& responsibilities);


};

class ManagerProjektow {
private:
    vector<Project*> projekty;
    vector<string> contributors;
    string responsibilities;

public:
    ManagerProjektow();

    const vector<Project*>& getProjekty() const;


    ~ManagerProjektow();
};



#endif // MANAGERPROJEKTOW_H
