
// ******************************************************************************** //
//                                                                                
//                                XML Data Binding                                
//                                                                                
//         Generated on: 20.10.2025. 9:30:07                                      
//       Generated from: C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xml   
//   Settings stored in: C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xdb   
//                                                                                
// ******************************************************************************** //

#ifndef   XMLLogoviH
#define   XMLLogoviH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLlogoviType;
typedef System::DelphiInterface<IXMLlogoviType> _di_IXMLlogoviType;
__interface IXMLlogType;
typedef System::DelphiInterface<IXMLlogType> _di_IXMLlogType;
__interface IXMLlogTypeList;
typedef System::DelphiInterface<IXMLlogTypeList> _di_IXMLlogTypeList;

// IXMLlogoviType 

__interface INTERFACE_UUID("{A533E1FB-64B2-4A44-893B-DA494F2223A3}") IXMLlogoviType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLlogType __fastcall Get_log(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLlogType __fastcall Add() = 0;
  virtual _di_IXMLlogType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLlogType log[const int Index] = { read=Get_log };/* default */
};

// IXMLlogType 

__interface INTERFACE_UUID("{A2A014B8-D910-4A34-A6FD-ADA00FA9FC03}") IXMLlogType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_datum() = 0;
  virtual System::UnicodeString __fastcall Get_id() = 0;
  virtual System::UnicodeString __fastcall Get_aktivnost() = 0;
  virtual void __fastcall Set_datum(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_id(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_aktivnost(const System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString datum = { read=Get_datum, write=Set_datum };
  __property System::UnicodeString id = { read=Get_id, write=Set_id };
  __property System::UnicodeString aktivnost = { read=Get_aktivnost, write=Set_aktivnost };
};

// IXMLlogTypeList 

__interface INTERFACE_UUID("{D23A189B-D018-4E39-B500-DDB1CB76B5C8}") IXMLlogTypeList : public Xml::Xmlintf::IXMLNodeCollection
{
public:
  // Methods & Properties 
  virtual _di_IXMLlogType __fastcall Add() = 0;
  virtual _di_IXMLlogType __fastcall Insert(const int Index) = 0;

  virtual _di_IXMLlogType __fastcall Get_Item(const int Index) = 0;
  __property _di_IXMLlogType Items[const int Index] = { read=Get_Item /* default */ };
};

// Forward Decls 

class TXMLlogoviType;
class TXMLlogType;
class TXMLlogTypeList;

// TXMLlogoviType 

class TXMLlogoviType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLlogoviType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLlogoviType 
  virtual _di_IXMLlogType __fastcall Get_log(const int Index);
  virtual _di_IXMLlogType __fastcall Add();
  virtual _di_IXMLlogType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLlogType 

class TXMLlogType : public Xml::Xmldoc::TXMLNode, public IXMLlogType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLlogType 
  virtual System::UnicodeString __fastcall Get_datum();
  virtual System::UnicodeString __fastcall Get_id();
  virtual System::UnicodeString __fastcall Get_aktivnost();
  virtual void __fastcall Set_datum(const System::UnicodeString Value);
  virtual void __fastcall Set_id(const System::UnicodeString Value);
  virtual void __fastcall Set_aktivnost(const System::UnicodeString Value);
};

// TXMLlogTypeList 

class TXMLlogTypeList : public Xml::Xmldoc::TXMLNodeCollection, public IXMLlogTypeList
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLlogTypeList 
  virtual _di_IXMLlogType __fastcall Add();
  virtual _di_IXMLlogType __fastcall Insert(const int Index);

  virtual _di_IXMLlogType __fastcall Get_Item(const int Index);
};

// Global Functions 

_di_IXMLlogoviType __fastcall Getlogovi(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLlogoviType __fastcall Getlogovi(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLlogoviType __fastcall Loadlogovi(const System::UnicodeString& FileName);
_di_IXMLlogoviType __fastcall  Newlogovi();

#define TargetNamespace ""

#endif