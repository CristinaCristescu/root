// @(#)root/cont
// Author: Bianca-Cristina Cristescu February 2014

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TListOfEnums                                                         //
//                                                                      //
// A collection of TEnum objects designed for fast access given a       //
// DeclId_t and for keep track of TEnum that were described             //
// unloaded enum.                                                       //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TListOfEnums.h"
#include "TClass.h"
#include "TExMap.h"
#include "TEnum.h"
#include "TGlobal.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"

ClassImp(TListOfEnums)

//______________________________________________________________________________
TListOfEnums::TListOfEnums(TClass *cl) : fClass(cl),fIds(0),fUnloaded(0),fIsLoaded(kFALSE)
{
   // Constructor.

   fIds = new TExMap;
   fUnloaded = new THashList;
}

//______________________________________________________________________________
TListOfEnums::~TListOfEnums()
{
   // Destructor.

   THashList::Delete();
   delete fIds;
   fUnloaded->Delete();
   delete fUnloaded;
}

//______________________________________________________________________________
void TListOfEnums::AddFirst(TObject *obj)
{
   // Add object at the beginning of the list.

   THashList::AddFirst(obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddFirst(TObject *obj, Option_t *opt)
{
   // Add object at the beginning of the list and also store option.
   // Storing an option is useful when one wants to change the behaviour
   // of an object a little without having to create a complete new
   // copy of the object. This feature is used, for example, by the Draw()
   // method. It allows the same object to be drawn in different ways.

   THashList::AddFirst(obj,opt);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddLast(TObject *obj)
{
   // Add object at the end of the list.

   THashList::AddLast(obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddLast(TObject *obj, Option_t *opt)
{
   // Add object at the end of the list and also store option.
   // Storing an option is useful when one wants to change the behaviour
   // of an object a little without having to create a complete new
   // copy of the object. This feature is used, for example, by the Draw()
   // method. It allows the same object to be drawn in different ways.

   THashList::AddLast(obj, opt);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddAt(TObject *obj, Int_t idx)
{
   // Insert object at location idx in the list.

   THashList::AddAt(obj, idx);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddAfter(const TObject *after, TObject *obj)
{
   // Insert object after object after in the list.

   THashList::AddAfter(after, obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddAfter(TObjLink *after, TObject *obj)
{
   // Insert object after object after in the list.

   THashList::AddAfter(after, obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddBefore(const TObject *before, TObject *obj)
{
   // Insert object before object before in the list.

   THashList::AddBefore(before, obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::AddBefore(TObjLink *before, TObject *obj)
{
   // Insert object before object before in the list.

   THashList::AddBefore(before, obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfEnums::Clear(Option_t *option)
{
   // Remove all objects from the list. Does not delete the objects unless
   // the THashList is the owner (set via SetOwner()).

   fUnloaded->Clear(option);
   fIds->Clear();
   THashList::Clear(option);
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
void TListOfEnums::Delete(Option_t *option /* ="" */)
{
   // Delete all TDataMember object files.

   fUnloaded->Delete(option);
   THashList::Delete(option);
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
TObject *TListOfEnums::FindObject(const char *name) const
{
   // Specialize FindObject to do search for the
   // a enum just by name or create it if its not already in the list

   TObject *result = THashList::FindObject(name);
   if (!result) {
      TInterpreter::DeclId_t decl;
      if (fClass) decl = gInterpreter->GetEnum(fClass, name);
      else        decl = gInterpreter->GetEnum(0, name);
      if (decl) result = const_cast<TListOfEnums*>(this)->Get(decl, name);
   }
   return result;
}

//______________________________________________________________________________
TEnum *TListOfEnums::Get(DeclId_t id, const char *name)
{
   // Return (after creating it if necessary) the TEnum
   // describing the enum corresponding to the Decl 'id'.

   if (!id) return 0;

   TEnum *e = (TEnum*)fIds->GetValue((Long64_t)id);
   if (!e) {
      if (fClass) {
         if (!gInterpreter->ClassInfo_Contains(fClass->GetClassInfo(),id)) return 0;
      } else {
         if (!gInterpreter->ClassInfo_Contains(0,id)) return 0;
      }

      // Let's see if this is a reload ...
      // can we check for reloads for enums?
      //const char *name = gInterpreter->DataMemberInfo_Name(info);
      e = (TEnum *)fUnloaded->FindObject(name);
      if (e) {
         e->Update(id);
      } else {
         if (fClass) e = new TEnum(name, false/*is global*/, (void*)id, fClass);
         else e = new TEnum(name, true/*is global*/, (void*)id, fClass);
      }
      // Calling 'just' THahList::Add would turn around and call
      // TListOfEnums::AddLast which should *also* do the fIds->Add.
      THashList::AddLast(e);
      fIds->Add((Long64_t)id,(Long64_t)e);
   }
   return e;
}

//______________________________________________________________________________
void TListOfEnums::RecursiveRemove(TObject *obj)
{
   // Remove object from this collection and recursively remove the object
   // from all other objects (and collections).
   // This function overrides TCollection::RecursiveRemove that calls
   // the Remove function. THashList::Remove cannot be called because
   // it uses the hash value of the hash table. This hash value
   // is not available anymore when RecursiveRemove is called from
   // the TObject destructor.

   if (!obj) return;

   THashList::RecursiveRemove(obj);
   fUnloaded->RecursiveRemove(obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   }
}

//______________________________________________________________________________
TObject* TListOfEnums::Remove(TObject *obj)
{
   // Remove object from the list.

   Bool_t found;

   found = THashList::Remove(obj);
   if (!found) {
      found = fUnloaded->Remove(obj);
   }
   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   }
   if (found) return obj;
   else return 0;
}

//______________________________________________________________________________
TObject* TListOfEnums::Remove(TObjLink *lnk)
{
   // Remove object via its objlink from the list.

   if (!lnk) return 0;

   TObject *obj = lnk->GetObject();

   THashList::Remove(lnk);
   fUnloaded->Remove(obj);

   if (fClass) {
      TEnum *d = dynamic_cast<TEnum*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   }
   return obj;
}

//______________________________________________________________________________
void TListOfEnums::Load()
{
   // Load all the DataMembers known to the intepreter for the scope 'fClass'
   // into this collection.

   if (fClass && fClass->GetClassInfo() == 0) return;

   gInterpreter->LoadEnums(fClass);
}
/*
//______________________________________________________________________________
void TListOfEnums::Unload()
{
   // Mark 'all func' as being unloaded.
   // After the unload, the data member can no longer be found directly,
   // until the decl can be found again in the interpreter (in which
   // the func object will be reused.

   TObjLink *lnk = FirstLink();
   while (lnk) {
      DeclId_t id;
      TDictionary *data = (TDictionary *)lnk->GetObject();
      if (fClass) id = ((TDataMember*)data)->GetDeclId();
      else id = ((TGlobal*)data)->GetDeclId();

      fIds->Remove((Long64_t)id);
      fUnloaded->Add(data);

      lnk = lnk->Next();
   }

   THashList::Clear();
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
void TListOfEnums::Unload(TDictionary *mem)
{
   // Mark 'func' as being unloaded.
   // After the unload, the data member can no longer be found directly,
   // until the decl can be found again in the interpreter (in which
   // the func object will be reused.

   if (THashList::Remove(mem)) {
      // We contains the object, let remove it from the other internal
      // list and move it to the list of unloaded objects.

      DeclId_t id;
      if (fClass) id = ((TDataMember*)mem)->GetDeclId();
      else id = ((TGlobal*)mem)->GetDeclId();
      fIds->Remove((Long64_t)id);
      fUnloaded->Add(mem);
   }
}
*/
