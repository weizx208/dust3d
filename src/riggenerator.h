#ifndef DUST3D_RIG_GENERATOR_H
#define DUST3D_RIG_GENERATOR_H
#include <QObject>
#include <QThread>
#include <QDebug>
#include "outcome.h"
#include "meshloader.h"
#include "autorigger.h"

class RigGenerator : public QObject
{
    Q_OBJECT
public:
    RigGenerator(const Outcome &outcome);
    ~RigGenerator();
    MeshLoader *takeResultMesh();
    std::vector<AutoRiggerBone> *takeResultBones();
    std::map<int, AutoRiggerVertexWeights> *takeResultWeights();
    const std::vector<QString> &missingMarkNames();
    const std::vector<QString> &errorMarkNames();
    Outcome *takeMeshResultContext();
    bool isSucceed();
signals:
    void finished();
public slots:
    void process();
private:
    Outcome *m_outcome = nullptr;
    MeshLoader *m_resultMesh = nullptr;
    AutoRigger *m_autoRigger = nullptr;
    std::vector<AutoRiggerBone> *m_resultBones = nullptr;
    std::map<int, AutoRiggerVertexWeights> *m_resultWeights = nullptr;
    std::vector<QString> m_missingMarkNames;
    std::vector<QString> m_errorMarkNames;
    bool m_isSucceed = false;
};

#endif
