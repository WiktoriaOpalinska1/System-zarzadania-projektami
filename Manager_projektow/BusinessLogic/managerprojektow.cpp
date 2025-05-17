#include "managerprojektow.h"
#include <iostream>


// ============ Projects ============
// Konstruktor
Project::Project(const string& name, const vector<string>& technologies, const string& status,
                 float workTime, const string& repositoryLink) {
    this->name = name;
    this->technologies = technologies;
    this->status = status;
    this->workTime = workTime;
    this->repositoryLink = repositoryLink;
}

// Gettery
string Project::getName() const {
    return name;
}

vector<string> Project::getTechnologies() const {
    return technologies;
}

string Project::getStatus() const {
    return status;
}

float Project::getWorkTime() const {
    return workTime;
}

string Project::getRepositoryLink() const {
    return repositoryLink;
}

// Settery
void Project::setName(const string& name) {
    this->name = name;
}

void Project::setTechnologies(const vector<string>& technologies) {
    this->technologies = technologies;
}

void Project::setStatus(const string& status) {
    this->status = status;
}

void Project::setWorkTime(float time) {
    this->workTime = time;
}

void Project::setRepositoryLink(const string& link) {
    this->repositoryLink = link;
}

// Pozostale funkcje
void Project::printInfo() const {
    cout << "=== Projekt ===" << endl;
    cout << "Nazwa: " << name << endl;
    cout << "Technologie: ";
    for (const auto& tech : technologies) {
        cout << tech << " ";
    }
    cout << endl;
    cout << "Stan: " << status << endl;
    cout << "Czas pracy: " << workTime << " h" << endl;
    cout << "Repozytorium: " << repositoryLink << endl;
}

string Project::toString() const {
    std::string result = "Nazwa: " + name + "\n";
    result += "Technologie: ";
    for (const auto& tech : technologies) {
        result += tech + " ";
    }
    result += "\nStan: " + status + "\n";
    result += "Czas pracy: " + std::to_string(workTime) + " h\n";
    result += "Repozytorium: " + repositoryLink + "\n";
    return result;
}

// ============ Team Projects ============
// Konstruktor
TeamProject::TeamProject(const string& name, const vector<string>& technologies, const string& status, float workTime,
                         const string& repositoryLink, const vector<string>& collaborators, const string& responsibilities)
    : Project(name, technologies, status, workTime, repositoryLink){
    this->collaborators = collaborators;
    this->responsibilities = responsibilities;
}

// Gettery
const vector<string>& TeamProject::getCollaborators() const {
    return collaborators;
}

const string& TeamProject::getResponsibilities() const {
    return responsibilities;
}


// Settery
void TeamProject::setCollaborators(const vector<string>& collaborators) {
    this->collaborators = collaborators;
}

void TeamProject::setResponsibilities(const string& responsibilities) {
    this->responsibilities = responsibilities;
}


// ============= Manager Projektow ===========
ManagerProjektow::ManagerProjektow() {
    projekty.push_back(new Project("CRM", {"C++", "Qt"}, "W trakcie", 100, "https://github.com/projekt/crm"));
    projekty.push_back(new TeamProject("Rezerwacje", {"C++", "Qt", "MySQL"}, "Zakończony", 200,
                                       "https://github.com/projekt/rezerwacje",
                                       {"Jan", "Anna"}, "Backend + GUI"));
}

const vector<Project*>& ManagerProjektow::getProjekty() const {
    return projekty;
}

ManagerProjektow::~ManagerProjektow() {
    for (auto* p : projekty)
        delete p;
}
