import { Module } from '@nestjs/common';
import { ConfigModule } from '@nestjs/config';

import { DataModule } from './data/data.module';
import { PrismaModule } from './prisma/prisma.module';

@Module({
  imports: [DataModule, PrismaModule, ConfigModule.forRoot({isGlobal:true})]
})
export class AppModule {}
