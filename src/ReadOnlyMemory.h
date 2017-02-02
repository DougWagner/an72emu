#ifndef READONLYMEMORY_H_INCLUDED
#define READONLYMEMORY_H_INCLUDED

namespace an72
{
    class ReadOnlyMemory
    {
        private:

            std::vector< uint8_t > _rawData;

        public:
            ReadOnlyMemory();
            virtual ~ReadOnlyMemory();

            ReadOnlyMemory( const ReadOnlyMemory& ) = delete;
    };
}

#endif // READONLYMEMORY_H_INCLUDED
