#ifndef CABROW_H
#define CABROW_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/collection>
#include <Wt/Dbo/ptr>

class CabRow
{
public:
    CabRow();

    int CabRowID;
    int DataCenterID;
    std::string Name;
    int ZoneID;
    template <class Action>
    void persist(Action &a){
        Wt::Dbo::field(a, CabRowID, "CabRowID");
        Wt::Dbo::field(a, DataCenterID, "DataCenterID");
        Wt::Dbo::field(a, Name, "Name");
        Wt::Dbo::field(a, ZoneID, "ZoneID");
    }
};
typedef Wt::Dbo::collection<Wt::Dbo::ptr<CabRow>>CabRows;
#endif // CABROW_H
