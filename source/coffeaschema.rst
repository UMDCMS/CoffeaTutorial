#######################
Defining coffea schemas
#######################

Suppose that you want to use coffea for your own analysis that uses a ntuple that
is not NANOAOD based. Now we will have to deal with the magic commands that tells
``coffea.nanoevents`` how they should the variable stored at the various branch
names should be packed together into uniform. This is known formally known as a
**schemas**, three already exist in the standard coffea installation. The ``BaseSchema``, which.