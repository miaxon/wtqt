#include <QCoreApplication>
#include <Wt/Utils>
#include <Wt/Dbo/Exception>
#include <Wt/Dbo/backend/MySQL>
#include <Wt/Dbo/Query>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/Session>
#include <Wt/WLogger>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/Dbo/Transaction>
#include <Wt/Dbo/Types>
#include <Wt/WString>
#include "cabrow.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Wt::log("info") << "test wt dbo with QT";
    Wt::Dbo::backend::MySQL conn("dcim","dcim","dcim","localhost");
    Wt::Dbo::Session session;
    session.setConnection(conn);
    session.mapClass<CabRow>("fac_CabRow");
    Wt::Dbo::Transaction trans(session);
    int count = session.query<int>("select count(*) from `fac_Ports`");
    Wt::log("info") << count;


    CabRows rows = session.find<CabRow>();
    for (const Wt::Dbo::ptr<CabRow> &row : rows){
        std::cout << row->Name;
    }
    return a.exec();
}
