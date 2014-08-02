#pragma once

namespace helper
{
    interface class IObjectComparison
    {
    public:
        int Compare(System::Object^, System::Object^);
    };

    class NativeCollectionItem
    {
        gcroot<System::Object^> _item;
        gcroot<IObjectComparison^> _compare;
    public:
        static gcroot<IObjectComparison^> Comparison(gcroot<System::Type^>);

        NativeCollectionItem();
        NativeCollectionItem(gcroot<System::Type^>, gcroot<System::Object^>);
        NativeCollectionItem(gcroot<IObjectComparison^>, gcroot<System::Object^>);
        friend bool operator < (const NativeCollectionItem&, const NativeCollectionItem&);
        friend bool operator == (const NativeCollectionItem&, const NativeCollectionItem&);
        gcroot<System::Object^> Item() const;
    };

    bool operator < (const NativeCollectionItem&, const NativeCollectionItem&);
    bool operator == (const NativeCollectionItem&, const NativeCollectionItem&);
}
