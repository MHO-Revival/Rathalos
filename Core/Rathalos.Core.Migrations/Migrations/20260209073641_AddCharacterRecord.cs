using System;
using System.Numerics;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Rathalos.Core.Migrations.Migrations
{
    /// <inheritdoc />
    public partial class AddCharacterRecord : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "characters",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    AccountId = table.Column<long>(type: "bigint", nullable: false),
                    RoleId = table.Column<decimal>(type: "numeric(20,0)", nullable: false),
                    RoleIndex = table.Column<int>(type: "integer", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Gender = table.Column<byte>(type: "smallint", nullable: false),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    HRLevel = table.Column<int>(type: "integer", nullable: false),
                    RoleState = table.Column<int>(type: "integer", nullable: false),
                    AvatarSetId = table.Column<byte>(type: "smallint", nullable: false),
                    FaceId = table.Column<int>(type: "integer", nullable: false),
                    HairId = table.Column<int>(type: "integer", nullable: false),
                    UnderclothesId = table.Column<int>(type: "integer", nullable: false),
                    SkinColor = table.Column<int>(type: "integer", nullable: false),
                    HairColor = table.Column<int>(type: "integer", nullable: false),
                    InnerColor = table.Column<int>(type: "integer", nullable: false),
                    EyeBall = table.Column<int>(type: "integer", nullable: false),
                    EyeColor = table.Column<int>(type: "integer", nullable: false),
                    FaceTattooIndex = table.Column<int>(type: "integer", nullable: false),
                    FaceTattooColor = table.Column<int>(type: "integer", nullable: false),
                    HideHelm = table.Column<bool>(type: "boolean", nullable: false),
                    HideFashion = table.Column<bool>(type: "boolean", nullable: false),
                    HideSuite = table.Column<bool>(type: "boolean", nullable: false),
                    StarLevel = table.Column<string>(type: "text", nullable: false),
                    SoulStoneLv = table.Column<int>(type: "integer", nullable: false),
                    FacialInfo = table.Column<string>(type: "jsonb", nullable: false),
                    MapId = table.Column<int>(type: "integer", nullable: false),
                    Position = table.Column<Quaternion>(type: "jsonb", nullable: false),
                    Experience = table.Column<long>(type: "bigint", nullable: false),
                    CreatedAt = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    LastLogin = table.Column<DateTime>(type: "timestamp with time zone", nullable: true),
                    PlaytimeSeconds = table.Column<long>(type: "bigint", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_characters", x => x.Id);
                    table.ForeignKey(
                        name: "FK_characters_accounts_AccountId",
                        column: x => x.AccountId,
                        principalTable: "accounts",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_characters_AccountId",
                table: "characters",
                column: "AccountId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "characters");
        }
    }
}
